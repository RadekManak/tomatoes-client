#include <iostream>
#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->startPomodoroButton, &QPushButton::clicked, this, &MainWindow::start_pomodoro);
    connect(ui->timerPage, &TimerWidget::timer_stopped, this, &MainWindow::cancel_pomodoro);
    connect(ui->timerPage, &TimerWidget::timer_finished, this, &MainWindow::finish_pomodoro);
    connect(ui->submitPage, &SubmitWidget::pomodoro_submitted, this, &MainWindow::submit_pomodoro);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setSession(std::shared_ptr<Session>& s){
    session = s;
}

void MainWindow::start_pomodoro() {
    ui->mainstackedWidget->setCurrentWidget(ui->timerPage);
    ui->timerPage->start_pomodoro();
}

void MainWindow::finish_pomodoro() {
    ui->mainstackedWidget->setCurrentWidget(ui->submitPage);
}

void MainWindow::cancel_pomodoro() {
    ui->mainstackedWidget->setCurrentWidget(ui->mainPage);
}

void MainWindow::submit_pomodoro(std::string& tags) {
    session->create_tomato(tags);
    ui->mainstackedWidget->setCurrentWidget(ui->mainPage);
}