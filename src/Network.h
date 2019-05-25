#pragma once

#include "iostream"
#include "cpprest/json.h"
#include "cpprest/http_client.h"

class Network{
private:
    web::http::client::http_client client;
    std::string github_token;
    std::string api_token;
public:
    Network(const std::string& server_uri, std::string githubToken, std::string apiToken);

    // Logging in/out
    void authenticate_session();
//    web::json::value delete_all_sessions();

    // Getting user info/updating
    web::json::value get_current_user_data();
//    web::json::value update_user_attributes();

    //creating tomatoes
//    web::json::value get_tomato_list();
//    web::json::value get_tomato_info();
//    web::json::value create_tomato();
//    web::json::value update_tomato();
//    web::json::value delete_tomato();

    //projects
//    web::json::value get_project_list();
//    web::json::value get_project_info();
//    web::json::value create_project();
//    web::json::value update_project();
//    web::json::value delete_project();

    //Leaderboards
//    web::json::value get_leadeboard();
private:
    web::http::http_response authenticated_request(web::http::http_request& req);
};
