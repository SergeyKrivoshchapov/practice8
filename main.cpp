#include"Smartphone.h"
#include"Catalog.h"
#include<iostream>
using namespace std;
Catalog InitializeCatalog() {
    Catalog catalog;
    catalog.addSmartphone("iPhone 12 Pro", Price(100, Valuta::USD), Manufacturer::APPLE,
    Color::WHITE, 64, Memory(6, MemoryMeasure::GB, 128, MemoryMeasure::GB), CPU::APPLE, OS::IOS);
    catalog.addSmartphone("iPhone 12 Pro", Price(102, Valuta::USD), Manufacturer::APPLE,
    Color::WHITE, 64, Memory(6, MemoryMeasure::GB, 129, MemoryMeasure::GB), CPU::APPLE, OS::IOS);
    catalog.addSmartphone("iPhone 12 Pro", Price(99, Valuta::USD), Manufacturer::APPLE,
    Color::WHITE, 64, Memory(6, MemoryMeasure::GB, 128, MemoryMeasure::GB), CPU::APPLE, OS::IOS);
    return catalog;
}
int main(int argc, char* argv[]) {
    Catalog catalog = InitializeCatalog();
    Smartphone whatBuyerLikes{"iPhone 12 pro", Price(100, Valuta::USD), Manufacturer::APPLE,
    Color::WHITE, 64 , Memory(6, MemoryMeasure::GB, 128, MemoryMeasure::GB), CPU::APPLE, OS::IOS};
    vector<Smartphone> results = catalog.search(whatBuyerLikes);
    if (!results.empty()) {
        for (Smartphone s : results) s.print();
    }
    else cout << "Sorry, we have nothing for you.";
    return 0;
}