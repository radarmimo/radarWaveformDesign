#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <uhd/utils/thread_priority.hpp>
#include <uhd/utils/safe_main.hpp>
#include <uhd/usrp/multi_usrp.hpp>
#include <uhd/exception.hpp>
#include <uhd/types/tune_request.hpp>
#include <boost/program_options.hpp>
#include <boost/format.hpp>
#include <boost/thread.hpp>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    uhd::usrp::multi_usrp::sptr usrp;

private slots:
    void on_pushButton_FindDevices_clicked();

    void on_pushButton_Plot_clicked();

    void on_pushButton_AddData_clicked();

    void on_pushButton_Connect_clicked();

private slots:
    void start_rx(uhd::usrp::multi_usrp::sptr &usrp);
    void process_data(QVector<double> &dataI, QVector<double> &dataQ);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
