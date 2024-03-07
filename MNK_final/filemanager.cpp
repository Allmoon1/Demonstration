#include "filemanager.h"


FileManager::FileManager(){
}
FileManager::~FileManager(){
}
std::pair<QList<QString>, QList<QString>> FileManager::load(){
    QFile file(fileName);
    if(file.open(QIODevice::ReadWrite))
        {
            QString tmp = QString(file.readAll());
            file.close();
            QList<QString> x;
            QList<QString> y;

            int j = 0;

            while (j != tmp.size()){
                QString t;
                int i = j;
                if (tmp[i] == '$'){break;}
                while (tmp[i] != '*'){
                    t += QString(tmp[i]);
                    i += 1;
                }
                x.append(t);
                j = i + 1;
            }
            int k = j+1;
            while (k != tmp.size()){

                QString t1;
                int o = k;
                if (tmp[o] == '#'){break;}
                while (tmp[o] != '*'){

                        t1 += QString(tmp[o]);
                        o += 1;

                }
                y.append(t1);
                k = o + 1;
            }
        return std::make_pair(x, y);
        }
}

void FileManager::save(QList<QList<double>> T){
    QFile file(fileName);
    QString str;
    for (int i = 0; i < T.size(); i++) {
        for (int j = 0; j < T[0].size(); j++) {
            if (i == 0){
                str += QString::number(T[i][j]) + "*";
            }
            if (i == 1 and j == 0){
                str += "$" + QString::number(T[i][j]) + "*";
            }
            else if (i == 1){
                str += QString::number(T[i][j]) + "*";
            }
        }
    }
    str += "#";
    if(file.open(QIODevice::ReadWrite))
        {
            file.write(str.toUtf8());
            file.resize(file.pos());
        }
    file.close();
}
