#pragma once
#include <cmath>
#include <stdexcept>
#include "Ram.h"


class Storage {
private:
    double storageAmount;
    MemoryMeasure storageMeasure;
public:
    Storage();
    Storage(double storageAmount, MemoryMeasure storageMeasure);

    void setStorageAmount(double storage_amount);
    void setStorageMeasure(MemoryMeasure storage_measure);
    double changeStorageMeasure(MemoryMeasure new_measure);

    double getStorageAmount() const;
    MemoryMeasure getStorageMeasure() const;
    bool operator>(const Storage& other_storage);
    std::string measureToString(MemoryMeasure measure);
};
