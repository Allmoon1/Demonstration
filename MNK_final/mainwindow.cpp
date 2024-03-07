#include "mainwindow.h"
#include "mnkcalc.h"
#include "ui_mainwindow.h"

#include "filemanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dataTable->setEnabled(false);
    ui->resButton->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
      ui->dataTable->setColumnCount(arg1);
      source->change_data(source->set_size(arg1, source->ret_data()));
      ui->dataTable->setEnabled(true);
      ui->resButton->setEnabled(true);
}

void MainWindow::on_dataTable_itemChanged(QTableWidgetItem *item)
{
    QString t = item->text();
    QRegExp re("[0-9]*\\.[0-9]*||[1-9][0-9]*||0||^-[0-9]*\\.[0-9]*||^-[1-9][0-9]*");
    if (!re.exactMatch(t)){
        item->setText("404.4");
    }
    source->change_data_item(item->row(), item->column(), item->text().toDouble());
}

void MainWindow::on_resButton_clicked()
{
    MnkCalculator calc;
    QString res = calc.calculate(source->ret_data());
    ui->labelRes->setText(res); 
    ui->spinBox->setEnabled(true);
    if (ui->checkSave->isChecked()){
        FileManager FM;
        auto tmp = source->set_size(ui->spinBox->value(), source->ret_data());
        FM.save(tmp);
    }
}

void MainWindow::on_loadCFG_clicked()
{
    FileManager FM;
    std::pair<QList<QString>, QList<QString>> t = FM.load();
    ui->spinBox->setValue(t.first.size());
    ui->textBrowser->clear();
    ui->textBrowser->setAlignment(Qt::AlignLeft);
    ui->textBrowser->insertPlainText("x: ");
    for (int i = 0; i < t.first.size(); i++) {
        ui->textBrowser->insertPlainText(t.first[i] + "  ");
        ui->dataTable->setItem(0, i, new QTableWidgetItem(t.first[i]));
        source->change_data_item(0, i, t.first[i].toDouble());
    }
    ui->textBrowser->insertPlainText("\n");
    ui->textBrowser->insertPlainText("y: ");
    for (int i = 0; i < t.second.size(); i++) {
        ui->textBrowser->insertPlainText(t.second[i] + "  ");
        ui->dataTable->setItem(1, i, new QTableWidgetItem(t.second[i]));
        source->change_data_item(1, i, t.second[i].toDouble());
    }

}
