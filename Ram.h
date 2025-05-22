#pragma once
#include <cmath>
#include <stdexcept>

enum class MemoryMeasure{ B, KB, MB, GB, TB, UNDEFINED};

class Ram {
    private:
    double ramAmount;
    MemoryMeasure ramMeasure;

    public:
    Ram();
    Ram(double ramAmount, MemoryMeasure ramMeasure);

    void setRamAmount(double ram_amount);
    void setRamMeasure(MemoryMeasure ram_measure);
    double changeRamMeasure(MemoryMeasure new_measure);

    double getRamAmount() const;
    MemoryMeasure getRamMeasure() const;
    bool operator>(const Ram& other_storage);
};