#include <iostream>
#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    break_time = false;
    finished_tomatoes = 0; //TODO get from server
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
    ui->timerPage->start_timer(Timer_type::pomodoro_timer);
}

void MainWindow::finish_pomodoro() {
    if (break_time){
        ui->mainstackedWidget->setCurrentWidget(ui->mainPage);
        break_time = false;
    } else {
        ui->mainstackedWidget->setCurrentWidget(ui->submitPage);
    }
}

void MainWindow::cancel_pomodoro() {
    ui->mainstackedWidget->setCurrentWidget(ui->mainPage);
    break_time = false;
}

void MainWindow::submit_pomodoro(std::string& tags) {
    session->create_tomato(tags);
    break_time = true;
    finished_tomatoes++;
    if (finished_tomatoes % 4 == 0){
        ui->timerPage->start_timer(Timer_type::break_timer_long);
    } else {
        ui->timerPage->start_timer(Timer_type::break_timer);
    }
    ui->mainstackedWidget->setCurrentWidget(ui->timerPage);
}