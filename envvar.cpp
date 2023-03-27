#include "envvar.hpp"

std::vector<std::string> GetEnvVar(std::string name){
    std::string val = getenv(name.c_str());
    if(val == ""){
        throw std::runtime_error("Environment variable " + name + " not found");
    }
    return Utility::split(val, ';');
}