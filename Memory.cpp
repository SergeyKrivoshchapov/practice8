#include "Memory.h"
#include <stdexcept>
#include <cmath>

Memory::Memory() {
    Ram();
    Storage();
}

Memory::Memory(double ram_amount, MemoryMeasure ram_measure, double storage_amount, MemoryMeasure storage_measure): ram(ram_amount, ram_measure), storage(storage_amount, storage_measure) {
    if (ram_amount < 0 || storage_amount < 0) throw std::invalid_argument("RAM or storage values cannot be negative");
    if (ram_measure == MemoryMeasure::UNDEFINED || storage_measure == MemoryMeasure::UNDEFINED)  throw std::invalid_argument("Memory always needs measure");
}

Ram Memory::getRam() const {
    return ram;
}

Storage Memory::getStorage() const {
    return storage;
}