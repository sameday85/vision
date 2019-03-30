#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void mouseDoubleClickEvent(QMouseEvent * event);

private:
    Ui::MainWindow *ui;

private:
    void initChart();
};

#endif // MAINWINDOW_H
