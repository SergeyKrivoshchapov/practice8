#include "Smartphone.h"
#include <iostream>
Smartphone::Smartphone() {
    this->model = ""; this->price = 0;
    this->manufacturer = Manufacturer::UNDEFINED;
    this->color = Color::UNDEFINED;
    this->displaySize = 0; this->ram = 0;
    this->storage = 0;
    this->cpu = CPU::UNDEFINED; this->os = OS::UNDEFINED;
}
Smartphone::Smartphone(string model, double price, Manufacturer manufacturer,
Color color, float displaySize, int ram, int storage, CPU cpu, OS os) {
    this->model = model;
    this->price = price;
    this->manufacturer = manufacturer;
    this->color = color;
    this->displaySize = displaySize;
    this->ram = ram;
    this->storage = storage;
    this->cpu = cpu;
    this->os = os;
}
string Smartphone::getModel() const { return model; }
Manufacturer Smartphone::getManufacturer() const { return manufacturer; }
Color Smartphone::getColor() const { return color; }
float Smartphone::getDisplay() const { return displaySize; }
int Smartphone::getRAM() const { return ram; }
int Smartphone::getStorage() const { return storage; }
CPU Smartphone::getCPU() const { return cpu; }
OS Smartphone::getOS() const { return os; }
double Smartphone::getPrice() const { return price; }
void Smartphone::setPrice(double price) { this->price = price; }

string Smartphone::colorToString(Color c) {
    switch (c) {
        case Color::WHITE: return "WHITE";
        case Color::GRAY: return "GRAY";
        case Color::BLACK: return "BLACK";
        case Color::BLUE: return "BLUE";
        case Color::RED: return "RED";
        case Color::GOLD: return "GOLD";
        case Color::YELLOW: return "YELLOW";
        case Color::GREEN: return "GREEN";
        case Color::BROWN: return "BROWN";
        default: return "UNDEFINED";
    }
}

string Smartphone::manufacturerToString(Manufacturer m) {
    switch (m) {
        case Manufacturer::APPLE: return "APPLE";
        case Manufacturer::SAMSUNG: return "SAMSUNG";
        case Manufacturer::XIAOMI: return "XIAOMI";
        case Manufacturer::HTC: return "HTC";
        case Manufacturer::HUAWEI: return "HUAWEI";
        case Manufacturer::GOOGLE: return "GOOGLE";
        case Manufacturer::PANASONIC: return "PANASONIC";
        default: return "UNDEFINED";
    }
}

string Smartphone::osToString(OS o) {
    switch (o) {
        case OS::ANDROID: return "ANDROID";
        case OS::IOS: return "IOS";
        case OS::WINDOWS: return "WINDOWS";
        case OS::GOOGLE: return "GOOGLE";
        case OS::BLACKBERRY: return "BLACKBERRY";
        default: return "UNDEFINED";
    }
}

string Smartphone::cpuToString(CPU cpu) {
    switch (cpu) {
        case CPU::SNAPDRAGON: return "SNAPDRAGON";
        case CPU::APPLE: return "APPLE";
        case CPU::EXYNOS: return "EXYNOS";
        case CPU::TENSOR: return "TENSOR";
        case CPU::TIGER: return "TIGER";
        default: return "UNDEFINED";
    }
}

void Smartphone::print() {
    if (model.empty()) {
        cout << "Sorry, we have nothing for you." << endl;
        return;
    }

    cout << "You might like this: ";
    cout << manufacturerToString(manufacturer) << " " << model << endl;
    cout << "Price: " << price << endl;
    cout << "Color: " << colorToString(color) << endl;
    cout << "Display: " << displaySize << endl;
    cout << "OS: " << osToString(os) << endl;
    cout << ram << "Gb RAM, " << storage << " GB storage" << endl;
    cout << "CPU: " << cpuToString(cpu) << endl;
}
