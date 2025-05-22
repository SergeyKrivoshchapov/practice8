#pragma once
#include "Ram.h"
#include "Storage.h"

class Memory {
private:
    Ram ram;
    Storage storage;
public:
    Memory();
    Memory(double ram_amount, MemoryMeasure ram_measure, double storageAmount, MemoryMeasure storage_measure);
    Ram getRam() const;
    Storage getStorage() const;
};