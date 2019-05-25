#include <memory>
#include "Session.h"

int main(int argc, char *argv[])
{
    auto session = std::make_unique<Session>();
    std::cout << session->get_user_info();
}