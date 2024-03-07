#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork/QNetworkProxy>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->checkBox_EB_Le->setEnabled(false);
    ui->checkBox_EB_Lo->setEnabled(false);
    ui->checkBox_EB_Ri->setEnabled(false);
    ui->checkBox_EB_Up->setEnabled(false);

    ui->edgeBlend_USP->setEnabled(false);
    ui->edgeBlend_UCW->setEnabled(false);

    ui->edgeBlend_LCW->setEnabled(false);
    ui->edgeBlend_RSP->setEnabled(false);
    ui->edgeBlend_LSP->setEnabled(false);
    ui->edgeBlend_LSPP->setEnabled(false);
    ui->edgeBlend_LeCW->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    serial->close();
    soket->close();
    delete serial;
    delete soket;
}

void MainWindow::on_exitButton_clicked()
{
        int t =  QMessageBox::question(this, "Выход из приложения","Вы уверены что хотите выйти?");
        switch (t) {
        case QMessageBox::Yes:
            close();
            break;
        case QMessageBox::No:
            break;
        }
}

void MainWindow::connectionToSerialPort(QString comPortName){
    serial = new QSerialPort(this);
    serial->setPortName(comPortName);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
}
void MainWindow::connectionTCP(QString ip, int port){
    soket = new QTcpSocket();
    soket->setProxy(QNetworkProxy::NoProxy);
    soket->connectToHost(ip , quint16(port));
}


void MainWindow::on_connectionButton_clicked()
{

    if (ui->protocol->currentText() == QString("RS-232")){
        toRs = true;
        connectionToSerialPort(ui->comPort->text());
    }
    else {
        toRs = false;
        connectionTCP(ui->p_ipAdress->text(), ui->p_port->text().toInt());
    }
}


void MainWindow::com_2_61(){
    int val = ui->blankingLower->value();
    QByteArray data;
    if (val < 10){
        data = ("\02" + QString("ADZZ;DBB:") + "00" + QString::number(val) + "\03").toLatin1();
    }
    else if (val >= 10 and val < 100) {
        data = ("\02" + QString("ADZZ;DBB:") + "0" + QString::number(val) + "\03").toLatin1();
    }
    else {
        data = ("\02" + QString("ADZZ;DBB:") + QString::number(val) + "\03").toLatin1();
    }

    if (toRs){
        serial->write(data);
    }
    else{
        soket->write(data);
        soket->waitForBytesWritten();
    }
}

void MainWindow::com_2_62(){
    int val = ui->blankingRight->value();
    QByteArray data;

    if (val < 10){
        data = ("\02" + QString("ADZZ;DBR:") + "00" + QString::number(val) + "\03").toLatin1();
    }
    else if (val >= 10 and val < 100) {
        data = ("\02" + QString("ADZZ;DBR:") + "0" + QString::number(val) + "\03").toLatin1();
    }
    else {
        data = ("\02" + QString("ADZZ;DBR:") + QString::number(val) + "\03").toLatin1();
    }

    if (toRs){
        serial->write(data);
    }
    else{
        soket->write(data);
        soket->waitForBytesWritten();
    }
}

void MainWindow::com_2_63(){
    int val = ui->blankingLeft->value();
    QByteArray data;

    if (val < 10){
        data = ("\02" + QString("ADZZ;DBL:") + "00" + QString::number(val) + "\03").toLatin1();
    }
    else if (val >= 10 and val < 100) {
        data = ("\02" + QString("ADZZ;DBL:") + "0" + QString::number(val) + "\03").toLatin1();
    }
    else {
        data = ("\02" + QString("ADZZ;DBL:") + QString::number(val) + "\03").toLatin1();
    }
    if (toRs){
        serial->write(data);
    }
    else{
        soket->write(data);
        soket->waitForBytesWritten();
    }
}

void MainWindow::com_2_64(){
    int val = ui->inRes_TotalDots->value();
    QByteArray data;
    if (val < 1000){
        data = ("\02" + QString("ADZZ;VTD:") + "0" + QString::number(val) + "\03").toLatin1();
    }
    else{
        data = ("\02" + QString("ADZZ;VTD:") + QString::number(val) + "\03").toLatin1();
    }
    if (toRs){
        serial->write(data);
    }
    else{
        soket->write(data);
        soket->waitForBytesWritten();
    }
}

void MainWindow::com_2_65(){
    int val = ui->inRes_DisplayDots->value();
    QByteArray data;
    if (val < 1000){
        data = ("\02" + QString("ADZZ;VDD:") + "0" + QString::number(val) + "\03").toLatin1();
    }
    else{
        data = ("\02" + QString("ADZZ;VDD:") + QString::number(val) + "\03").toLatin1();
    }
    if (toRs){
        serial->write(data);
    }
    else{
        soket->write(data);
        soket->waitForBytesWritten();
    }
}

void MainWindow::com_2_66(){
    int val = ui->inRes_TotalLines->value();
    QByteArray data;
    if (val < 1000){
        data = ("\02" + QString("ADZZ;VTL:") + "0" + QString::number(val) + "\03").toLatin1();
    }
    else{
        data = ("\02" + QString("ADZZ;VTL:") + QString::number(val) + "\03").toLatin1();
    }
    if (toRs){
        serial->write(data);
    }
    else{
        soket->write(data);
        soket->waitForBytesWritten();
    }
}

void MainWindow::com_2_67(){
    int val = ui->inRes_DisplayLines->value();
    QByteArray data;
    if (val < 1000){
        data = ("\02" + QString("ADZZ;VDL:") + "0" + QString::number(val) + "\03").toLatin1();
    }
    else{
        data = ("\02" + QString("ADZZ;VDL:") + QString::number(val) + "\03").toLatin1();
    }
    if (toRs){
        serial->write(data);
    }
    else{
        soket->write(data);
        soket->waitForBytesWritten();
    }
}

void MainWindow::com_2_68(){
    int val = ui->clampPos->value();
    QByteArray data;
    if (val < 10){
        data = ("\02" + QString("ADZZ;VLT:") + "00" + QString::number(val) + "\03").toLatin1();
    }
    else if (val >= 10 and val < 100) {
        data = ("\02" + QString("ADZZ;VLT:") + "0" + QString::number(val) + "\03").toLatin1();
    }
    else {
        data = ("\02" + QString("ADZZ;VLT:") + QString::number(val) + "\03").toLatin1();
    }
    if (toRs){
        serial->write(data);
    }
    else{
        soket->write(data);
        soket->waitForBytesWritten();
    }
}

void MainWindow::com_2_69(){
    QByteArray data;
    auto val = ui->checkBox_BE->checkState();
    if (val == Qt::Checked){
        data = ("\02" + QString("ADZZ;VXX:EDBI0=+") + "00001" + "\03").toLatin1();
    }
    else{
        data = ("\02" + QString("ADZZ;VXX:EDBI0=+") + "00000" + "\03").toLatin1();
    }


    if (toRs){
        serial->write(data);
    }
    else{
        soket->write(data);
        soket->waitForBytesWritten();
    }
}

void MainWindow::com_2_70(){
    int val = ui->edgeBlend_USP->value();
    QByteArray data;
    if (val < 10){
        data = ("\02" + QString("ADZZ;VEU:") + "000" + QString::number(val) + "\03").toLatin1();
    }
    else if (val >= 10 and val < 100){
        data = ("\02" + QString("ADZZ;VEU:") + "00" + QString::number(val) + "\03").toLatin1();
    }
    else {
        data = ("\02" + QString("ADZZ;VEU:") + "0" + QString::number(val) + "\03").toLatin1();
    }


    if (toRs){
        serial->write(data);
    }
    else{
        soket->write(data);
        soket->waitForBytesWritten();
    }
}

void MainWindow::com_2_71(){
    QByteArray data;
    auto val = ui->checkBox_EB_Up->checkState();
    if (val == Qt::Checked){
        data = ("\02" + QString("ADZZ;VGU:") + "1" + "\03").toLatin1();
    }
    else{
        data = ("\02" + QString("ADZZ;VGU:") + "0" + "\03").toLatin1();

    }
    if (toRs){
        serial->write(data);
    }
    else{
        soket->write(data);
        soket->waitForBytesWritten();
    }
}


void MainWindow::com_2_72(){
    int val = ui->edgeBlend_UCW->value();
    QByteArray data;
    if (val < 10){
        data = ("\02" + QString("ADZZ;VXX:EUWI0=+") + "0000" + QString::number(val) + "\03").toLatin1();
    }
    else if (val >= 10 and val < 100){
        data = ("\02" + QString("ADZZ;VXX:EUWI0=+") + "000" + QString::number(val) + "\03").toLatin1();
    }
    else {
        data = ("\02" + QString("ADZZ;VXX:EUWI0=+") + "00" + QString::number(val) + "\03").toLatin1();
    }


    if (toRs){
        serial->write(data);
    }
    else{
        soket->write(data);
        soket->waitForBytesWritten();
    }
}

void MainWindow::com_2_73(){
    int val = ui->edgeBlend_LSP->value();
    QByteArray data;
    if (val < 10){
        data = ("\02" + QString("ADZZ;VEB:") + "000" + QString::number(val) + "\03").toLatin1();
    }
    else if (val >= 10 and val < 100){
        data = ("\02" + QString("ADZZ;VEB:") + "00" + QString::number(val) + "\03").toLatin1();
    }
    else {
        data = ("\02" + QString("ADZZ;VEB:") + "0" + QString::number(val) + "\03").toLatin1();
    }


    if (toRs){
        serial->write(data);
    }
    else{
        soket->write(data);
        soket->waitForBytesWritten();
    }
}

void MainWindow::com_2_74(){
    QByteArray data;
    auto val = ui->checkBox_EB_Lo->checkState();
    if (val == Qt::Checked){
        data = ("\02" + QString("ADZZ;VGB:") + "1" + "\03").toLatin1();
    }
    else{
        data = ("\02" + QString("ADZZ;VGB:") + "0" + "\03").toLatin1();
    }
    if (toRs){
        serial->write(data);
    }
    else{
        soket->write(data);
        soket->waitForBytesWritten();
    }
}

void MainWindow::com_2_75(){
    int val = ui->edgeBlend_LCW->value();
    QByteArray data;
    if (val < 10){
        data = ("\02" + QString("ADZZ;VXX:EBWI0=+") + "0000" + QString::number(val) + "\03").toLatin1();
    }
    else if (val >= 10 and val < 100){
        data = ("\02" + QString("ADZZ;VXX:EBWI0=+") + "000" + QString::number(val) + "\03").toLatin1();
    }
    else {
        data = ("\02" + QString("ADZZ;VXX:EBWI0=+") + "00" + QString::number(val) + "\03").toLatin1();
    }


    if (toRs){
        serial->write(data);
    }
    else{
        soket->write(data);
        soket->waitForBytesWritten();
    }
}

void MainWindow::com_2_76(){
    int val = ui->edgeBlend_LSPP->value();
    QByteArray data;
    if (val < 10){
        data = ("\02" + QString("ADZZ;VEL:") + "000" + QString::number(val) + "\03").toLatin1();
    }
    else if (val >= 10 and val < 100){
        data = ("\02" + QString("ADZZ;VEL:") + "00" + QString::number(val) + "\03").toLatin1();
    }
    else if (val >= 100 and val < 1000){
        data = ("\02" + QString("ADZZ;VEL:") + "0" + QString::number(val) + "\03").toLatin1();
    }
    else {
        data = ("\02" + QString("ADZZ;VEL:") + QString::number(val) + "\03").toLatin1();
    }


    if (toRs){
        serial->write(data);
    }
    else{
        soket->write(data);
        soket->waitForBytesWritten();
    }
}

void MainWindow::com_2_77(){
    QByteArray data;
    auto val = ui->checkBox_EB_Le->checkState();
    if (val == Qt::Checked){
        data = ("\02" + QString("ADZZ;VGL:") + "1" + "\03").toLatin1();
    }
    else{
        data = ("\02" + QString("ADZZ;VGL:") + "0" + "\03").toLatin1();
    }
    if (toRs){
        serial->write(data);
    }
    else{
        soket->write(data);
        soket->waitForBytesWritten();
    }
}

void MainWindow::com_2_78(){
    int val = ui->edgeBlend_LeCW->value();
    QByteArray data;
    if (val < 10){
        data = ("\02" + QString("ADZZ;VXX:ELWI0=+") + "0000" + QString::number(val) + "\03").toLatin1();
    }
    else if (val >= 10 and val < 100){
        data = ("\02" + QString("ADZZ;VXX:ELWI0=+") + "000" + QString::number(val) + "\03").toLatin1();
    }
    else if (val >= 100 and val < 1000){
        data = ("\02" + QString("ADZZ;VXX:ELWI0=+") + "00" + QString::number(val) + "\03").toLatin1();
    }
    else {
        data = ("\02" + QString("ADZZ;VXX:ELWI0=+") + "0" + QString::number(val) + "\03").toLatin1();
    }


    if (toRs){
        serial->write(data);
    }
    else{
        soket->write(data);
        soket->waitForBytesWritten();
    }
}
void MainWindow::com_2_79(){
    int val = ui->edgeBlend_RSP->value();
    QByteArray data;
    if (val < 10){
        data = ("\02" + QString("ADZZ;VER:") + "000" + QString::number(val) + "\03").toLatin1();
    }
    else if (val >= 10 and val < 100){
        data = ("\02" + QString("ADZZ;VER:") + "00" + QString::number(val) + "\03").toLatin1();
    }
    else if (val >= 100 and val < 1000){
       data = ("\02" + QString("ADZZ;VER:") + "0" + QString::number(val) + "\03").toLatin1();
    }
    else {
        data = ("\02" + QString("ADZZ;VER:") + QString::number(val) + "\03").toLatin1();
    }


    if (toRs){
        serial->write(data);
    }
    else{
        soket->write(data);
        soket->waitForBytesWritten();
    }
}

void MainWindow::com_2_80(){
    QByteArray data;
    auto val = ui->checkBox_EB_Ri->checkState();
    if (val == Qt::Checked){
        data = ("\02" + QString("ADZZ;VGR:") + "1" + "\03").toLatin1();
    }
    else{
        data = ("\02" + QString("ADZZ;VGR:") + "0" + "\03").toLatin1();
    }
    if (toRs){
        serial->write(data);
    }
    else{
        soket->write(data);
        soket->waitForBytesWritten();
    }
}

void MainWindow::on_blankingLower_sliderPressed()
{
    connect(ui->blankingLower, &QSlider::valueChanged, ui->lcdBL, QOverload<int>::of(&QLCDNumber::display));
}
void MainWindow::on_blankingLower_sliderReleased()
{
    com_2_61();
}
void MainWindow::on_blankingRight_sliderPressed()
{
   connect(ui->blankingRight, &QSlider::valueChanged, ui->lcdBRi, QOverload<int>::of(&QLCDNumber::display));
}
void MainWindow::on_blankingRight_sliderReleased()
{
    com_2_62();
}

void MainWindow::on_blankingLeft_sliderPressed()
{
    connect(ui->blankingLeft, &QSlider::valueChanged, ui->lcdBLe, QOverload<int>::of(&QLCDNumber::display));
}

void MainWindow::on_blankingLeft_sliderReleased()
{
     com_2_63();
}

void MainWindow::on_inRes_TotalDots_sliderPressed()
{
    connect(ui->inRes_TotalDots, &QSlider::valueChanged, ui->lcdiRTD, QOverload<int>::of(&QLCDNumber::display));
}

void MainWindow::on_inRes_TotalDots_sliderReleased()
{
    com_2_64();
}

void MainWindow::on_inRes_DisplayDots_sliderPressed()
{
    connect(ui->inRes_DisplayDots, &QSlider::valueChanged, ui->lcdiRDD, QOverload<int>::of(&QLCDNumber::display));
}

void MainWindow::on_inRes_DisplayDots_sliderReleased()
{
    com_2_65();
}

void MainWindow::on_inRes_TotalLines_sliderPressed()
{
    connect(ui->inRes_TotalLines, &QSlider::valueChanged, ui->lcdiRTL, QOverload<int>::of(&QLCDNumber::display));
}

void MainWindow::on_inRes_TotalLines_sliderReleased()
{
    com_2_66();
}

void MainWindow::on_inRes_DisplayLines_sliderPressed()
{
    connect(ui->inRes_DisplayLines, &QSlider::valueChanged, ui->lcdiRDL, QOverload<int>::of(&QLCDNumber::display));
}

void MainWindow::on_inRes_DisplayLines_sliderReleased()
{
    com_2_67();
}

void MainWindow::on_clampPos_sliderPressed()
{
    connect(ui->clampPos, &QSlider::valueChanged, ui->lcdCP, QOverload<int>::of(&QLCDNumber::display));
}

void MainWindow::on_clampPos_sliderReleased()
{
    com_2_68();
}

void MainWindow::on_edgeBlend_USP_sliderPressed()
{
    connect(ui->edgeBlend_USP, &QSlider::valueChanged, ui->lcdEB_USP, QOverload<int>::of(&QLCDNumber::display));
}

void MainWindow::on_edgeBlend_USP_sliderReleased()
{
    com_2_70();
}
void MainWindow::on_edgeBlend_UCW_sliderPressed()
{
    connect(ui->edgeBlend_UCW, &QSlider::valueChanged, ui->lcdEB_UCW, QOverload<int>::of(&QLCDNumber::display));

}

void MainWindow::on_edgeBlend_UCW_sliderReleased()
{
    com_2_72();
}

void MainWindow::on_edgeBlend_LSP_sliderPressed()
{
    connect(ui->edgeBlend_LSP, &QSlider::valueChanged, ui->lcdEB_LSP, QOverload<int>::of(&QLCDNumber::display));
}

void MainWindow::on_edgeBlend_LSP_sliderReleased()
{
    com_2_73();
}

void MainWindow::on_edgeBlend_LCW_sliderPressed()
{
    connect(ui->edgeBlend_LCW, &QSlider::valueChanged, ui->lcdEB_LCW, QOverload<int>::of(&QLCDNumber::display));
}

void MainWindow::on_edgeBlend_LCW_sliderReleased()
{
    com_2_75();
}

void MainWindow::on_edgeBlend_LSPP_sliderPressed()
{
    connect(ui->edgeBlend_LSPP, &QSlider::valueChanged, ui->lcdEB_LSPP, QOverload<int>::of(&QLCDNumber::display));
}

void MainWindow::on_edgeBlend_LSPP_sliderReleased()
{
    com_2_76();
}

void MainWindow::on_edgeBlend_LeCW_sliderPressed()
{
    connect(ui->edgeBlend_LeCW, &QSlider::valueChanged, ui->lcdEB_LeCW, QOverload<int>::of(&QLCDNumber::display));
}

void MainWindow::on_edgeBlend_LeCW_sliderReleased()
{
    com_2_78();
}



void MainWindow::on_edgeBlend_RSP_sliderPressed()
{
    connect(ui->edgeBlend_RSP, &QSlider::valueChanged, ui->lcdEB_RSP, QOverload<int>::of(&QLCDNumber::display));

}

void MainWindow::on_edgeBlend_RSP_sliderReleased()
{
    com_2_79();
}

void MainWindow::on_checkBox_BE_stateChanged(int arg1)
{
    if (arg1 == 2){
        com_2_69();
        ui->checkBox_EB_Le->setEnabled(true);
        ui->checkBox_EB_Lo->setEnabled(true);
        ui->checkBox_EB_Ri->setEnabled(true);
        ui->checkBox_EB_Up->setEnabled(true);
    }
    else{
        com_2_69();
        ui->checkBox_EB_Le->setEnabled(false);
        ui->checkBox_EB_Lo->setEnabled(false);
        ui->checkBox_EB_Ri->setEnabled(false);
        ui->checkBox_EB_Up->setEnabled(false);

        ui->edgeBlend_USP->setEnabled(false);
        ui->edgeBlend_UCW->setEnabled(false);
        ui->edgeBlend_LCW->setEnabled(false);
        ui->edgeBlend_RSP->setEnabled(false);
        ui->edgeBlend_LSP->setEnabled(false);
        ui->edgeBlend_LSPP->setEnabled(false);
        ui->edgeBlend_LeCW->setEnabled(false);
    }
}

void MainWindow::on_checkBox_EB_Up_stateChanged(int arg1)
{
    if (arg1 == 2){
        ui->edgeBlend_USP->setEnabled(true);
        ui->edgeBlend_UCW->setEnabled(true);
    }
    else{
        ui->edgeBlend_USP->setEnabled(false);
        ui->edgeBlend_UCW->setEnabled(false);
    }
    com_2_71();
}

void MainWindow::on_checkBox_EB_Lo_stateChanged(int arg1)
{
    if (arg1 == 2){
        ui->edgeBlend_LSP->setEnabled(true);
        ui->edgeBlend_LCW->setEnabled(true);
    }
    else{
        ui->edgeBlend_LSP->setEnabled(false);
        ui->edgeBlend_LCW->setEnabled(false);
    }
    com_2_74();
}

void MainWindow::on_checkBox_EB_Le_stateChanged(int arg1)
{
    if (arg1 == 2){
        ui->edgeBlend_LSPP->setEnabled(true);
        ui->edgeBlend_LeCW->setEnabled(true);
    }
    else{
        ui->edgeBlend_LSPP->setEnabled(false);
        ui->edgeBlend_LeCW->setEnabled(false);
    }
    com_2_77();
}

void MainWindow::on_checkBox_EB_Ri_stateChanged(int arg1)
{
    if (arg1 == 2){
        ui->edgeBlend_RSP->setEnabled(true);

    }
    else{
        ui->edgeBlend_RSP->setEnabled(false);
    }
    com_2_80();
}
