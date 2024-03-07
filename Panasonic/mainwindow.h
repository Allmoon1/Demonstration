#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>
#include <QtNetwork/QTcpSocket>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_exitButton_clicked();
    void connectionToSerialPort(QString comPortName);
    void connectionTCP(QString ip, int port);
    void on_connectionButton_clicked();

    void com_2_61();
    void com_2_62();
    void com_2_63();
    void com_2_64();
    void com_2_65();
    void com_2_66();
    void com_2_67();
    void com_2_68();
    void com_2_69();
    void com_2_70();
    void com_2_71();
    void com_2_72();
    void com_2_73();
    void com_2_74();
    void com_2_75();
    void com_2_76();
    void com_2_77();
    void com_2_78();
    void com_2_79();
    void com_2_80();

    void on_blankingLower_sliderPressed();
    void on_blankingLower_sliderReleased();
    void on_blankingRight_sliderPressed();
    void on_blankingRight_sliderReleased();
    void on_blankingLeft_sliderPressed();
    void on_blankingLeft_sliderReleased();
    void on_inRes_TotalDots_sliderPressed();
    void on_inRes_TotalDots_sliderReleased();
    void on_inRes_DisplayDots_sliderPressed();
    void on_inRes_DisplayDots_sliderReleased();
    void on_inRes_TotalLines_sliderPressed();
    void on_inRes_TotalLines_sliderReleased();
    void on_inRes_DisplayLines_sliderPressed();
    void on_inRes_DisplayLines_sliderReleased();
    void on_clampPos_sliderPressed();
    void on_clampPos_sliderReleased();
    void on_edgeBlend_USP_sliderPressed();
    void on_edgeBlend_USP_sliderReleased();
    void on_edgeBlend_UCW_sliderPressed();
    void on_edgeBlend_UCW_sliderReleased();
    void on_edgeBlend_LSP_sliderPressed();
    void on_edgeBlend_LSP_sliderReleased();
    void on_edgeBlend_LCW_sliderPressed();
    void on_edgeBlend_LCW_sliderReleased();
    void on_edgeBlend_LSPP_sliderPressed();
    void on_edgeBlend_LSPP_sliderReleased();
    void on_edgeBlend_LeCW_sliderPressed();
    void on_edgeBlend_LeCW_sliderReleased();
    void on_edgeBlend_RSP_sliderPressed();
    void on_edgeBlend_RSP_sliderReleased();
    void on_checkBox_BE_stateChanged(int arg1);
    void on_checkBox_EB_Up_stateChanged(int arg1);
    void on_checkBox_EB_Lo_stateChanged(int arg1);
    void on_checkBox_EB_Le_stateChanged(int arg1);
    void on_checkBox_EB_Ri_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QTcpSocket *soket;
    bool toRs;
};



#endif // MAINWINDOW_H
