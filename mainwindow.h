#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFutureWatcher>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //
    void busy_job();

private:
    //
    int do_busy_job();

    //
    void busy_job_finished();

private:
    Ui::MainWindow *ui;

    //
    QFutureWatcher<int>* watcher_;
};

#endif // MAINWINDOW_H
