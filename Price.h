#pragma once
#include <string>

enum class Valuta { RUB, EUR, USD, GBP, UNDEFINED };

class Price {
    private:
    double price;
    Valuta valuta;
    public:
    Price();
    Price(double price, Valuta valuta);
    void setPrice(double price);
    void setValuta(Valuta valuta);
    double convertToValuta(const Valuta valuta_tochange) const;
    double amountPrice() const;
    Valuta getValuta() const;
    std::string valutaToString (Valuta valuta);
    bool operator<(const Price& other);
};

