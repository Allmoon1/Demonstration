#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QDebug>
#include <QLineEdit>
#include <QStandardItemModel>
#include <QVector>
#include <QGraphicsScene>
#include <QtNumeric>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "sourcedata.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow(); 
protected:
    Ui::MainWindow *ui;
private:
    SourceData* source = new SourceData;
private slots:
    void on_loadCFG_clicked();
    void on_spinBox_valueChanged(int arg1);
    void on_dataTable_itemChanged(QTableWidgetItem *item);
    void on_resButton_clicked();
};

#endif // MAINWINDOW_H
