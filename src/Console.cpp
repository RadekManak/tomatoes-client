#include "Console.h"
#include <chrono>
#include <thread>

using namespace std::string_literals;

Console::Console(std::shared_ptr<Session> &session): session(session) {
}

void Console::attach(){
    std::string input;
    std::cout << "Tomato.es console client" << std::endl;
    while (true){
        std::cout << "> ";
        std::getline(std::cin, input);
        if (input == "exit"){
            break;
        } else if (input == "start"){
            start_pomodoro();
        } else{
            std::cout << "Invalid command. Available are (start exit)" << std::endl;
        }
    }
}

void Console::start_pomodoro(){
    std::cout << "comma separated list of tags: ";
    std::string tags;
    std::getline(std::cin, tags);
    for (int i = 25; i != 0; --i) {
        std::cout << "\rTime remaining " << i << " minutes.";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::minutes(1));
    }
    std::cout << "\rTime's up!" << std::endl << "Type create or cancel: ";
    std::string input;
    std::getline(std::cin, input);
    if (input == "create"){
        auto result = session->create_tomato(tags);
        std::cout << "Tomato created!" << std::endl;
    } else if (input == "cancel"){
        return;
    }
}