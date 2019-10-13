#pragma once

#include <string>
#include <vector>

struct Tomatoes_counters{
    int day;
    int week;
    int month;
};

struct Authorizations{
    std::string provider;
    std::string uid;
    std::string nickname;
    std::string image;
};

struct User_info {
    explicit User_info();
    explicit User_info(web::json::value json);

    std::string id;
    std::string name;
    std::string email;
    std::string image;
    std::string time_zone;
    std::string color;
    int volume{};
    bool ticking{};
    int work_hours_per_day{};
    int average_hourly_rate{};
    std::string currency;
    std::string currency_unit;
    Tomatoes_counters tomatoes_counters{};
    std::vector<Authorizations> authorizations;
    std::string created_at;
    std::string updated_at;
};