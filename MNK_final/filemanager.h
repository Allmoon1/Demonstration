#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "mainwindow.h"

class FileManager{
private:
    QString const fileName = "cfg.txt";
public:
    FileManager();
    std::pair<QList<QString>, QList<QString>> load();
    void save(QList<QList<double>> T);
    ~FileManager();

};


#endif // FILEMANAGER_H
