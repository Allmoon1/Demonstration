#ifndef MNKCALC_H
#define MNKCALC_H

#include "mainwindow.h"

class MnkCalculator{
public:
    MnkCalculator();
    QString calculate(QList<QList<double>> lst);
    ~MnkCalculator();
};

#endif // MNKCALC_H
