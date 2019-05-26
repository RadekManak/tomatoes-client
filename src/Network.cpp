#include "Network.h"

using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

Network::Network(const std::string &server_uri, std::string &githubToken, std::string &apiToken) :
    client(server_uri),
    github_token(githubToken),
    api_token(apiToken) {}

// Logging in/out
void Network::authenticate_session() {
    json::value postData;
    postData["provider"] = json::value::string("github");
    postData["access_token"] = json::value::string(github_token);

    pplx::create_task([&](){
        return client.request(methods::POST, "/api/session", postData, pplx::cancellation_token::none());
    })
    .then([&](http_response response){
        if (response.status_code() == status_codes::OK){
            api_token = response.extract_json().get()["token"].as_string();
        } else {
            throw http_exception(response.status_code(), "error while authenticating");
        }
    }).wait();
}
//json::value Network::delete_all_sessions(){}

// Getting user info/updating
json::value Network::get_current_user_data(){
    http_request request(methods::GET);
    request.set_request_uri("/api/user");
    http_response response = authenticated_request(request);

    auto status_code = response.status_code();
    if (status_code == status_codes::OK){
        return response.extract_json().get();
    }
    return -1;
}

//json::value Network::update_user_attributes(){}
//creating tomatoes
//json::value Network::get_tomato_list(){}
//json::value Network::get_tomato_info(){}
json::value Network::create_tomato(const std::string& tags){
    json::value postData;
    json::value tomato = json::value::object();
    tomato["tag_list"] = json::value::string(tags);
    postData["tomato"] = tomato;

    http_request request(methods::POST);
    request.set_request_uri("/api/tomatoes");
    request.set_body(postData);
    http_response response = authenticated_request(request);
    return response.extract_json().get();
}
//json::value Network::update_tomato(){}

//json::value Network::delete_tomato(){}
//projects
//json::value Network::get_project_list(){}
//json::value Network::get_project_info(){}
//json::value Network::create_project(){}
//json::value Network::update_project(){}

//json::value Network::delete_project(){}

//Leaderboards
//json::value Network::get_leadeboard(){}

http_response Network::authenticated_request(http_request& req) {
    bool auth_attempted = false;
    if (api_token.empty()){
        std::cout << "API token was empty attempting to auth";
        authenticate_session();
        auth_attempted = true;
    }
    req.headers().add("Authorization", api_token);
    pplx::task<http_response> response = client.request(req);

    if (response.get().status_code() == status_codes::Unauthorized && !auth_attempted){
        std::cout << "Unauthorized! Requesting new API key." << std::endl;
        authenticate_session();
        req.headers().remove("Authorization");
        req.headers().add("Authorization", api_token);
        response = client.request(req);
    }
    std::cout << "Final response was: " << response.get().status_code() << std::endl << "JSON: "
        << response.get().extract_json().get().serialize();
    return response.get();
}
