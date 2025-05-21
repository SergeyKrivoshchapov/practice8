#pragma once
#include "Price.h"
#include <string>
using namespace std;
enum class Manufacturer {
    APPLE, SAMSUNG, XIAOMI, HTC, HUAWEI, GOOGLE, PANASONIC, UNDEFINED};
enum class Color {
    WHITE, GRAY, BLACK, BLUE, RED, GOLD, YELLOW, GREEN, BROWN, UNDEFINED};
enum class OS {
    ANDROID, IOS, WINDOWS, GOOGLE, BLACKBERRY, UNDEFINED};
enum class CPU {
    SNAPDRAGON, APPLE, EXYNOS, TENSOR, TIGER, UNDEFINED};
class Smartphone {
private:
    string model; Manufacturer manufacturer; Color color;
    float displaySize; int ram, storage;
    CPU cpu; OS os; Price price;
public:
    Smartphone();
    Smartphone(string model, Price price, Manufacturer manufacturer,
    Color color, float displaySize, int ram,
    int storage, CPU cpu, OS os);
    string getModel() const;
    Manufacturer getManufacturer() const;
    Color getColor() const;
    float getDisplay() const;
    int getRAM() const;
    int getStorage() const;
    CPU getCPU() const;
    OS getOS() const;
    Price getPrice() const;
    void setPrice(Price price);
    string colorToString(Color c);
    string manufacturerToString(Manufacturer m);
    string osToString(OS o);
    string cpuToString(CPU cpu);
    void print();
};