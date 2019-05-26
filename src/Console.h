#pragma once

#include <memory>
#include "Session.h"

class Console {
private:
    std::shared_ptr<Session> session;
    void start_pomodoro();
public:
    explicit Console(std::shared_ptr<Session>& session);
    void attach();
};