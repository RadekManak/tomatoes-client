#pragma once

#include <QWidget>
#include <chrono>
#include <QtCore/QTimer>
#include <memory>

enum class Timer_type{
    pomodoro_timer,
    break_timer,
    break_timer_long
};

namespace Ui {
class TimerWidget;
}

class TimerWidget : public QWidget {
Q_OBJECT
    std::unique_ptr<QTimer> qtimer;
    std::chrono::system_clock::time_point end_date;

protected slots:

    void timer_tick();

public:
    explicit TimerWidget(QWidget *parent = nullptr);

    ~TimerWidget() override;

    Ui::TimerWidget *ui;
signals:
    void timer_finished();
    void timer_stopped();

public slots:
    void stop_pomodoro();
    void start_timer(Timer_type type);
};

static std::string format_duration(std::chrono::system_clock::duration duration);