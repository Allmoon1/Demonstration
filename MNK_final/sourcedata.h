#ifndef SOURCEDATA_H
#define SOURCEDATA_H

#include <QList>

class SourceData{
private:
    QList<QList<double>> T;
public:
    SourceData();
    QList<QList<double>> set_size(int n, QList<QList<double>> t);
    void change_data(QList<QList<double>> chT);
    void change_data_item(int r, int c, double item);
    QList<QList<double>> ret_data();
    ~SourceData();
};

#endif // SOURCEDATA_H
