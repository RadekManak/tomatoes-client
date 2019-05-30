#pragma once

#include <QWidget>

namespace Ui {
class SubmitWidget;
}

class SubmitWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SubmitWidget(QWidget *parent = nullptr);
    ~SubmitWidget() override;
signals:
    void pomodoro_submitted(std::string& tags);
private slots:
    void submit_pomodoro();
private:
    Ui::SubmitWidget *ui;
};