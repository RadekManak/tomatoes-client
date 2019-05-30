#include "TimerWidget.h"
#include "ui_TimerWidget.h"

TimerWidget::TimerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimerWidget)
{
    ui->setupUi(this);
    connect(ui->resetPomodoroButton, &QPushButton::clicked, this, &TimerWidget::stop_pomodoro);
}

TimerWidget::~TimerWidget()
{
    delete ui;
    delete qtimer;
}

void TimerWidget::stop_pomodoro(){
    qtimer->stop();
    emit timer_stopped();
}

void TimerWidget::start_pomodoro() {
    countdown = 25*60;
    qtimer = new QTimer(this);
    connect(qtimer, SIGNAL(timeout()), this, SLOT(timer_tick()));
    qtimer->start(5);
}

void TimerWidget::timer_tick() {
    if (countdown == 1){
        qtimer->stop();
        emit timer_finished();
    }
    countdown -= 1;
    int minutes = countdown/60;
    int seconds = countdown%60;
    std::string zero_min;
    if (minutes < 10){
        zero_min = "0";
    }
    std::string zero_sec;
    if (seconds < 10){
        zero_sec = "0";
    }
    std::string time = zero_min + std::to_string(minutes) + ":" + zero_sec + std::to_string(seconds);
    ui->clockLabel->setText(time.c_str());
}