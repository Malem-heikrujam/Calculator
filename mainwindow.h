#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    enum Operation{ NONE, ADD, SUBTRACT, MULTIPLY};
    Operation operation = NONE;
    double firstNum = 0.0;

private:
    Ui::MainWindow *ui;

private slots:
    void digit_pressed();

private slots:
    void binary_pressed();
    void on_pushButton_dot_pressed();
    void on_pushButton_clear_pressed();

    void on_pushButton_equals_pressed();
};

#endif // MAINWINDOW_H
