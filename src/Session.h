#pragma once

#include "iostream"
#include "Network.h"

class Session {
private:
    std::unique_ptr<Network> network;
public:
    std::string github_token;
    std::string api_token;
public:
    Session();
    bool load_user_from_file();

    std::string get_user_info();

    std::string create_tomato(const std::string &tags);
};