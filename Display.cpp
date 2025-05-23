#include "Display.h"

#include <stdexcept>

Display::Display() {
    this->width = 0;
    this->height = 0;
    this->diag = 0;
    this->measure = MonitorMeasure::UNDEFINED;
}

Display::Display(double width, double height, double diag, MonitorMeasure measure, int colors) {
    if (width <= 0 || height <= 0 || diag <= 0) throw std::invalid_argument("width and height and diag cannot be negative");
    if (measure == MonitorMeasure::UNDEFINED) throw std::invalid_argument("Monitor measure cannot be undefined");
    this->width = width;
    this->height = height;
    this->diag = diag;
    this->measure = measure;
    this->colors = colors;
}

void Display::setWidth(double width) {
    this->width = width;
}

void Display::setHeight(double height) {
    this->height = height;
}

void Display::setDiag(double diag) {
    this->diag = diag;
}

void Display::changeMonitorMeasure(MonitorMeasure new_measure) {
    if (measure == new_measure) return
}
