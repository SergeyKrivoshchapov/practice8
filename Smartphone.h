#pragma once
#include "Price.h"
#include "Memory.h"
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
    float displaySize; Memory memory;
    CPU cpu; OS os; Price price;
public:
    Smartphone();
    Smartphone(string model, Price price, Manufacturer manufacturer,
    Color color, float displaySize, Memory memory, CPU cpu, OS os);
    string getModel() const;
    Manufacturer getManufacturer() const;
    Color getColor() const;
    float getDisplay() const;
    Memory getMemory() const;
    CPU getCPU() const;
    OS getOS() const;
    Price getPrice() const;
    Ram getRam() const;
    Storage getStorage() const;
    void setPrice(Price price);
    string colorToString(Color c);
    string manufacturerToString(Manufacturer m);
    string osToString(OS o);
    string cpuToString(CPU cpu);
    string measureToString(const MemoryMeasure measure);
    string priceToString(Price price);
    string storageToString(Memory storage);
    void print();
};