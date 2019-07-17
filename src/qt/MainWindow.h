#pragma once
#include <QMainWindow>
#include <memory>
#include <src/Session.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    std::shared_ptr<Session> session;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void setSession(std::shared_ptr<Session>& session);

private slots:
    void start_pomodoro();
    void finish_pomodoro();
    void cancel_pomodoro();
    void submit_pomodoro(std::string& tags);

private:
    Ui::MainWindow *ui;
    bool break_time;
    int finished_tomatoes;
};