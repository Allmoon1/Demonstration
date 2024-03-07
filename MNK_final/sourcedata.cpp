#include "sourcedata.h"
#include <QList>

SourceData::SourceData(){

}
SourceData::~SourceData(){

}

QList<QList<double>> SourceData::set_size(int n, QList<QList<double>> t){
    QList<QList<double>> res;
    if (t.size() == 0){
        for (int i = 0; i < 2; i++) {
            QList<double> tmp;
            for (int j = 0; j < n; j++) {
                tmp.append(0.0);
            }
            res.append(tmp);
        }
    }
    else if (n > t[0].size()) {
        for (int i = 0; i < 2; i++) {
            QList<double> tmp;
            for (int j = 0; j < n; j++) {

                if (j >= t[0].size()){
                    tmp.append(0.0);
                }
                else{
                    tmp.append(t[i][j]);
                }
            }
            res.append(tmp);
        }
    }
    else {
        for (int i = 0; i < 2; i++) {
            QList<double> tmp;
            for (int j = 0; j < n; j++) {
                tmp.append(t[i][j]);
            }
            res.append(tmp);
        }
    }

    return res;
}

void SourceData::change_data(QList<QList<double>> chT){
    T = chT;
}

QList<QList<double>> SourceData::ret_data(){
    return T;
}

void SourceData::change_data_item(int r, int c, double item){
    T[r][c] = item;
}
