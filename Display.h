#pragma once

enum class MonitorMeasure {INCHES, SM, UNDEFINED};

class Display {
private:
    double width;
    double height;
    double diag;
    MonitorMeasure measure;
    int colors;
public:
    Display();
    Display(double width, double height, double diag, MonitorMeasure measure, int colors);

    double getWidth();
    double getHeight();
    double getDiag();
    MonitorMeasure getMonitorMeasure();
    int getColors();

    void setWidth(double width);
    void setHeight(double height);
    void setDiag(double diag);
    void changeMonitorMeasure(MonitorMeasure new_measure);
    void setColors(int colors);
};