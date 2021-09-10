#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "main.h"

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
    void Change_Limit(int);
    void Auto_Draw(int);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
