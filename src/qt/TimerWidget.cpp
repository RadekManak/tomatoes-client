#include "TimerWidget.h"
#include "ui_TimerWidget.h"
#include <chrono>

TimerWidget::TimerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimerWidget)
{
    ui->setupUi(this);
    connect(ui->resetPomodoroButton, &QPushButton::clicked, this, &TimerWidget::stop_pomodoro);
    qtimer = std::make_unique<QTimer>();
    connect(qtimer.get(), SIGNAL(timeout()), this, SLOT(timer_tick()));
}

TimerWidget::~TimerWidget()
{
    delete ui;
}

void TimerWidget::stop_pomodoro(){
    qtimer->stop();
    emit timer_stopped();
}

void TimerWidget::start_pomodoro() {
    std::chrono::milliseconds duration = std::chrono::minutes{25};
    end_date = std::chrono::system_clock::now() + duration;
    timer_tick();
    qtimer->start(1000);
}

void TimerWidget::timer_tick() {
    if (end_date <= std::chrono::system_clock::now()){
        qtimer->stop();
        emit timer_finished();
        return;
    }
    auto time_left = end_date - std::chrono::system_clock::now();
    ui->clockLabel->setText(format_duration(time_left).c_str());
}

static std::string format_duration(std::chrono::system_clock::duration duration){
    using namespace std;
    chrono::minutes min = chrono::duration_cast<chrono::minutes>(duration);
    duration = duration-min;
    chrono::seconds sec = chrono::duration_cast<chrono::seconds>(duration);
    char out[20];
    sprintf(out, "%02d:%02d", (int)min.count(), (int)sec.count());
    return out;
}