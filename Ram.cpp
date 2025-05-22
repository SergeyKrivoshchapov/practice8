#include "Ram.h"
#include <iostream>
Ram::Ram() {
    this -> ramAmount = 0;
    this -> ramMeasure = MemoryMeasure::UNDEFINED;
}

Ram::Ram(double ramAmount, MemoryMeasure ramMeasure) {
    if (ramAmount < 0) throw std::invalid_argument("Ram amount cannot be less than zero");
    if (ramMeasure == MemoryMeasure::UNDEFINED) throw std::invalid_argument("Memory always needs measure");
    this->ramAmount = ramAmount;
    this->ramMeasure = ramMeasure;
}

void Ram::setRamAmount(double ram_amount) {
    this->ramAmount = ram_amount;
}

void Ram::setRamMeasure(MemoryMeasure ramMeasure) {
    this->ramMeasure = ramMeasure;
}

double Ram::changeRamMeasure(MemoryMeasure new_measure) {
    if (ramMeasure == new_measure) return ramAmount;
    if (ramMeasure == MemoryMeasure::UNDEFINED || new_measure == MemoryMeasure::UNDEFINED) throw std::invalid_argument("Memory always needs measure");
    int from = static_cast<int>(ramMeasure);
    int to = static_cast<int>(new_measure);
    const int diff_exp = from - to;

    return ramAmount * std::pow(1024, diff_exp);
}

double Ram::getRamAmount() const{
    return this->ramAmount;
}

MemoryMeasure Ram::getRamMeasure() const {
    return this->ramMeasure;
}

bool Ram::operator>(const Ram &other_ram){
    if (ramMeasure == MemoryMeasure::UNDEFINED || other_ram.ramMeasure == MemoryMeasure::UNDEFINED) return false;
    if (ramMeasure == other_ram.ramMeasure) return ramAmount > other_ram.ramAmount;
    return (changeRamMeasure(other_ram.ramMeasure) > other_ram.ramAmount);
}
