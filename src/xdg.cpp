#include <string>
#include <cstring>
#include "xdg.h"


std::string xdg::config_home(){
    char* XDG_CONFIG_HOME = getenv("XDG_CONFIG_HOME");
    if (XDG_CONFIG_HOME == nullptr){
        XDG_CONFIG_HOME = getenv("HOME");
        strcat(XDG_CONFIG_HOME, "/.config");
    }
    return std::string(XDG_CONFIG_HOME);
}