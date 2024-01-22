#include <iostream>

// Абстракція (інтерфейс)
class IDevice {
public:
    virtual void operate() const = 0;
};

// Низькорівнева реалізація - конкретний клас
class LightSwitch : public IDevice {
public:
    void operate() const override {
        std::cout << "Light switch is toggled\n";
    }
};

// Низькорівнева реалізація - конкретний клас
class FanSwitch : public IDevice {
public:
    void operate() const override {
        std::cout << "Fan switch is toggled\n";
    }
};

// Високорівневий модуль, який залежить від абстракції
class RemoteControl {
private:
    const IDevice& device;

public:
    RemoteControl(const IDevice& dev) : device(dev) {}

    void pressButton() const {
        device.operate();
    }
};

int main() {
    // Використання принципу інверсії залежностей
    LightSwitch lightSwitch;
    FanSwitch fanSwitch;

    RemoteControl remote1(lightSwitch);
    RemoteControl remote2(fanSwitch);

    remote1.pressButton();  // Виведе: "Light switch is toggled"
    remote2.pressButton();  // Виведе: "Fan switch is toggled"

    return 0;
}
