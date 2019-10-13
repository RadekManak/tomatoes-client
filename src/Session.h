#pragma once

#include "iostream"
#include "Network.h"
#include "User_info.h"

class Session {
private:
    std::unique_ptr<Network> network;
public:
    std::string github_token;
    std::string api_token;
    User_info userInfo;
public:
    Session();
    bool load_user_from_file();

    void update_user_info();

    std::string create_tomato(const std::string &tags);
};