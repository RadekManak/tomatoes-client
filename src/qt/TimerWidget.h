#pragma once

#include <QWidget>
#include <QtCore/QTimer>

namespace Ui {
class TimerWidget;
}

class TimerWidget : public QWidget {
Q_OBJECT
    int countdown;
    QTimer *qtimer;

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
    void start_pomodoro();
};