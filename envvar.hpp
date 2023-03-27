#ifndef __ENVVAR_HPP__
#define __ENVVAR_HPP__

#include <string>
#include <vector>

#include <cutility.hpp>

#include <stdexcept>

#include <iostream>

std::vector<std::string> GetEnvVar(std::string name);

int SetEnvVar(std::string name, std::string value);
int SetEnvVar(std::string name, std::vector<std::string> value);

int AppendEnvVar(std::string name, std::string value);

#endif