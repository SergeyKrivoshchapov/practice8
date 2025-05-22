#pragma once
#include<string>
#include<vector>
#include "Smartphone.h"
#include "Price.h"
#include "Memory.h"
using namespace std;
class Catalog {
private:
    vector<Smartphone> smartphones;
public:
    void addSmartphone(string model, Price price, Manufacturer manufacturer,
    Color color, float displaySize, Memory memory, CPU cpu, OS os);
    Smartphone getSmartphone(string model);
    vector<Smartphone> search(const Smartphone& searchSmartphone);
};