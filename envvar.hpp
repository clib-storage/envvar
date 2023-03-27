#ifndef __ENVVAR_HPP__
#define __ENVVAR_HPP__

#include <string>
#include <vector>

#include <cutility.hpp>

#include <stdexcept>

std::vector<std::string> GetEnvVar(std::string name);

#endif