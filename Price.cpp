#include "Price.h"
#include <stdexcept>

Price::Price() {
    this->price = 0;
    this->valuta = Valuta::UNDEFINED;
}

Price::Price(double price, Valuta valuta) {
    if (price < 0) throw std::invalid_argument("Price cannot be less than zero");
    if (valuta == Valuta::UNDEFINED) throw std::invalid_argument("Price always needs measure");
    this->price = price;
    this->valuta = valuta;
}

void Price::setPrice(double price) {
    if (price < 0) {
        throw std::invalid_argument("Price cannot less than zero");
    }
    this->price = price;
}

void Price::setValuta(Valuta valuta) {
    this->valuta = valuta;
}

double Price::amountPrice() const{
   return this->price;
}

Valuta Price::getValuta() const {
    return this->valuta;
}

double Price::convertToValuta(const Valuta valuta_tochange) const{
    static double table[4][4] = {
        {1, 0.011, 0.013, 0.093}, // RUB
        {90.59, 1, 1.13, 0.84}, //EUR
        {79.85, 0.88, 1, 0.74}, // USD
        {107.38, 1.19, 1.34, 1} // GBP
    };

    if (valuta == valuta_tochange) return price;
    if (valuta_tochange == Valuta::UNDEFINED || valuta == Valuta::UNDEFINED) throw std::invalid_argument("Price always needs measure");

    int from = static_cast<int>(valuta);
    int to = static_cast<int>(valuta_tochange);
    if (from < 0 || from > 3 || to < 0 || to > 3) throw std::out_of_range("cannot convert valuta because it is undefined");

    return price * table[from][to];
}

std::string Price::valutaToString(Valuta valuta) {
    switch (valuta) {
        case Valuta::RUB : return "RUB";
        case Valuta::EUR : return "EUR";
        case Valuta::USD : return "USD";
        case Valuta::GBP : return "GBP";
        default: return "UNDEFINED";
    }
}

bool Price::operator<(const Price &other) {
    if (valuta == Valuta::UNDEFINED || other.valuta == Valuta::UNDEFINED) return false;
    if (valuta == other.valuta) return price < other.price;
    return convertToValuta(other.valuta) < other.price;
}

