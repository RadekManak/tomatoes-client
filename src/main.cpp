#include <memory>
#include "Session.h"
#include "Console.h"

int main(int argc, char *argv[])
{
    auto session = std::make_shared<Session>();
    Console console(session);
    console.attach();
}