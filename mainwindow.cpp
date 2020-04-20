#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtConcurrent>
#include <QFuture>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //
    watcher_ = new QFutureWatcher<int>;
    connect(watcher_, &QFutureWatcher<int>::finished,
            this, &MainWindow::busy_job_finished);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::busy_job()
{
    // 若有需要, 启动告知对话框

    auto future = QtConcurrent::run(this, &MainWindow::do_busy_job);
    watcher_->setFuture(future);
}

int MainWindow::do_busy_job()
{
    return 1;
}

void MainWindow::busy_job_finished()
{
    // 若有需要, 关闭通知对话框

    qDebug() << "busy job finished!";
    qDebug() << "the returned value is: "
             << watcher_->result();
}

