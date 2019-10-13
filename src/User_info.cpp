#include <cpprest/json.h>
#include "User_info.h"

User_info::User_info() = default;

User_info::User_info(web::json::value json) {
    std::string as_str = json.serialize();
    name = json["name"].as_string();
    tomatoes_counters.day = json["tomatoes_counters"]["day"].as_integer();
    tomatoes_counters.week = json["tomatoes_counters"]["week"].as_integer();
    tomatoes_counters.month = json["tomatoes_counters"]["month"].as_integer();
}