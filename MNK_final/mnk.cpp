#include "mnkcalc.h"

MnkCalculator::MnkCalculator(){

}
MnkCalculator::~MnkCalculator(){

}
QString MnkCalculator::calculate(QList<QList<double>> lst){

    int n = lst[0].size();
    double tmp_x = 0;
    double tmp_y = 0;
    double tmp_xy = 0;
    double tmp_xx = 0;
    QList<double> list = {};
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n; j++){
            if (i == 0){
                tmp_x += lst[i][j];
                list.append(lst[i][j]);
                tmp_xx += lst[i][j] * lst[i][j];
            }
            else{
                tmp_y += lst[i][j];
                tmp_xy += lst[i][j] * list[j];
            }
        }
    }
    double a = (n * tmp_xy - tmp_x * tmp_y) / (n * tmp_xx - tmp_x*tmp_x);
    double b = (tmp_y - a * tmp_x) / n;
    QString y;
    if (qIsNaN(a) || qIsNaN(b)) {
        y = "Ошибка. Некоректные данные";
    }
    else{
        y = "y = " + QString::number(a) + " * " + "x" + " + " + QString::number(b);
    }
    return y;
}



