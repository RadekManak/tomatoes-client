#include <string>
#include <cstring>
#include "xdg.h"


const std::string xdg::config_home(){
    char* XDG_CONFIG_HOME = getenv("XDG_CONFIG_HOME");
    if (XDG_CONFIG_HOME == nullptr){
        std::string HOME = std::string(getenv("HOME"));
        return HOME + "/.config";
    } else {
        return std::string(XDG_CONFIG_HOME);
    }
}