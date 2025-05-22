#include "Storage.h"

Storage::Storage() {
    this -> storageAmount = 0;
    this -> storageMeasure = MemoryMeasure::UNDEFINED;
}

Storage::Storage(double storageAmount, MemoryMeasure storageMeasure) {
    if (storageAmount < 0) throw std::invalid_argument("Storage amount cannot be less than zero");
    if (storageMeasure == MemoryMeasure::UNDEFINED) throw std::invalid_argument("Memory always needs measure");
    this->storageAmount = storageAmount;
    this->storageMeasure = storageMeasure;
}

void Storage::setStorageAmount(double storage_amount) {
    this->storageAmount = storage_amount;
}

void Storage::setStorageMeasure(MemoryMeasure storageMeasure) {
    this->storageMeasure = storageMeasure;
}

double Storage::changeStorageMeasure(MemoryMeasure new_measure) {
    if (storageMeasure == new_measure) return storageAmount;
    if (storageMeasure == MemoryMeasure::UNDEFINED || new_measure == MemoryMeasure::UNDEFINED) throw std::invalid_argument("Memory always needs measure");
    int from = static_cast<int>(storageMeasure);
    int to = static_cast<int>(new_measure);
    const int diff_exp = from - to;

    return storageAmount * std::pow(1024, diff_exp);
}

double Storage::getStorageAmount() const{
    return this->storageAmount;
}

MemoryMeasure Storage::getStorageMeasure() const {
    return this->storageMeasure;
}

bool Storage::operator>(const Storage &other_storage){
    if (storageMeasure == MemoryMeasure::UNDEFINED || other_storage.storageMeasure == MemoryMeasure::UNDEFINED) return false;
    if (storageMeasure == other_storage.storageMeasure) return storageAmount > other_storage.storageAmount;
    return (changeStorageMeasure(other_storage.storageMeasure) > other_storage.storageAmount);
}
