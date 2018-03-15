#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_StartButton_clicked();

private:
    Ui::MainWindow *ui;
    void loadTextFile();
    void writeTextFile();

};

#endif // MAINWINDOW_H
