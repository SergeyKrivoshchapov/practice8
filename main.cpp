#include"Smartphone.h"
#include"Catalog.h"
#include<iostream>
using namespace std;
Catalog InitializeCatalog() {
    Catalog catalog;
    catalog.addSmartphone("iPhone 12 Pro", Price(100, Valuta::USD), Manufacturer::APPLE,
    Color::WHITE, 6, 3, 64, CPU::APPLE, OS::IOS);
    catalog.addSmartphone("iPhone 12 Pro", Price(102, Valuta::USD), Manufacturer::APPLE,
    Color::WHITE, 6, 3, 128, CPU::APPLE, OS::IOS);
    catalog.addSmartphone("iPhone 12 Pro", Price(99, Valuta::RUB), Manufacturer::APPLE,
    Color::WHITE, 6, 3, 64, CPU::APPLE, OS::IOS);
    return catalog;
}
int main(int argc, char* argv[]) {
    Catalog catalog = InitializeCatalog();
    Smartphone whatBuyerLikes{"iphone 12 pro", Price(101, Valuta::USD), Manufacturer::APPLE,
    Color::WHITE, 0 , 0, 0, CPU::UNDEFINED, OS::UNDEFINED};
    vector<Smartphone> results = catalog.search(whatBuyerLikes);
    if (!results.empty()) {
        for (Smartphone s : results) s.print();
    }
    else cout << "Sorry, we have nothing for you.";
    return 0;
}