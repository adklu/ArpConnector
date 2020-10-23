#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <alsa/asoundlib.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:    
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
   void slotrec();
   void slotstop();
   void input();
   void output();
   void wait();
   void wait1();
   void autoconnect();
   void loadselectioncomboBoxKeyOut();
   void loadselectioncomboBoxArpOut();
   void loadselectioncomboBoxClockOut();
   void loadselectioncomboBoxArpIn();
   void loadselectioncomboSynthIn();
   void loadselectioncomboBoxClockIn();


   void on_pushButtonPath_pressed();
   void on_pushButtonKey_pressed();
   void on_pushButtonArpIn_pressed();
   void on_pushButtonArpOut_pressed();
   void on_pushButtonSynthIn_pressed();
   void on_pushButtonClockOut_pressed();
   void on_pushButtonClockIn_pressed();
   void on_pushButtonAuto_pressed();
};

#endif // MAINWINDOW_H
