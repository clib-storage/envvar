#include "envvar.hpp"

/**
 * @brief Get the Environment Variable 'name' as a vector of strings
 * 
 * @param name the name of the environment variable
 * @return a vector of strings, each string is a value of the environment variable
 */
std::vector<std::string> GetEnvVar(std::string name){
    std::string val = getenv(name.c_str());
    if(val == ""){
        throw std::runtime_error("Environment variable " + name + " not found");
    }
    return Utility::split(val, ';');
}


/**
 * @brief Set the Environment Variable 'name' to 'value'
 * @param name the name of the environment variable
 * @param value  the value of the environment variable
 * @warning when modyfing an environment variable, the change will not be applied to the current process,
 * 			you will need to restart the process for the change to take effect
 * @return int 0 if successful, -1 if not
 */
int SetEnvVar(std::string name, std::string value){
	#ifdef _WIN32
		std::string cmd = "setx " + name + " \"" + value + "\"";
	#else
		std::string cmd = "export " + name + " \"" + value + "\"";
	#endif
	return system(cmd.c_str());
}

/**
 * @brief Set the Environment Variable 'name' to 'value'
 * 
 * @param name the name of the environment variable
 * @param value a vector of strings, each string is a value of the environment variable
 * @return int 0 if successful, -1 if not
 * @warning when modyfing an environment variable, the change will not be applied to the current process,
 * 			you will need to restart the process for the change to take effect
 */
int SetEnvVar(std::string name, std::vector<std::string> value){
	std::string val = "";
	for(auto i : value){
		val += i + ";";
	}
	return SetEnvVar(name, val);
}

/**
 * @brief Append a value to the Environment Variable 'name'
 * 
 * @param name the name of the environment variable where the value will be appended
 * @param value the value to append
 * @return int 0 if successful, -1 if not
 * @warning when modyfing an environment variable, the change will not be applied to the current process,
* 			you will need to restart the process for the change to take effect
 */
int AppendEnvVar(std::string name, std::string value){
	std::vector<std::string> val = GetEnvVar(name);
	val.push_back(value);
	return SetEnvVar(name, val);
}