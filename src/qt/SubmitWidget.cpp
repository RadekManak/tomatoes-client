#include "SubmitWidget.h"
#include "ui_SubmitWidget.h"

SubmitWidget::SubmitWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubmitWidget)
{
    ui->setupUi(this);
    connect(ui->submitButton, &QPushButton::clicked, this, &SubmitWidget::submit_pomodoro);
}

SubmitWidget::~SubmitWidget()
{
    delete ui;
}

void SubmitWidget::submit_pomodoro() {
    auto tags = ui->lineEdit->text().toStdString();
    emit pomodoro_submitted(tags);
}