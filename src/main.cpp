#include <memory>
#include "Session.h"
#include "Console.h"
#include <QApplication>
#include "src/qt/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    auto session = std::make_shared<Session>();
    w.setSession(session);
    w.show();
    return a.exec();
}