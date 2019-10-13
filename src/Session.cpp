#include "Session.h"

#include <utility>
#include "Network.h"
#include "xdg.h"

#include "cpprest/http_client.h"
#include "cpprest/filestream.h"
#include "iostream"
#include "fstream"
#include "cpprest/json.h"

using namespace web;

Session::Session(){
    load_user_from_file();
    network = std::make_unique<Network>("http://www.tomato.es", github_token, api_token);
    update_user_info();
}

void Session::update_user_info(){
    auto response = network->get_current_user_data();
    userInfo = User_info{response};
}

std::string Session::create_tomato(const std::string& tags){
    auto response = network->create_tomato(tags);
    return response.serialize();
}

bool Session::load_user_from_file() {
    std::fstream users_file;
    users_file.open(xdg::config_home() + "/tomatoes-client/users.json", std::ios::in);
    json::value users = json::value::parse(users_file);
    github_token = users["github_token"].as_string();
    api_token = users["api_token"].as_string();
    return !github_token.empty();
}