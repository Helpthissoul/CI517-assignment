#ifndef __ENGINE_COMMON_H__
#define __ENGINE_COMMON_H__

#include <exception>
#include <iostream>
#include <string>


#define __DEBUG

inline void debug(const char* msg, const char* details = "") {
	std::cout << "DEBUG: " << msg << " " << details << std::endl;
}

inline void debug(const char* msg, int value) {
	std::cout << "DEBUG: " << msg << " " << value << std::endl;
}

class EngineException : public std::exception {
private:
	std::string message;

public:
	
	EngineException(std::string arg0, std::string arg1 = "") : message("EngineException: " + arg0 + " - " + arg1) {
		std::cout << "\t" << message << std::endl;
	}

	EngineException(const char* arg0, const char* arg1) : EngineException(std::string(arg0), std::string(arg1)) {}

	virtual const char* what() const throw() {
		return message.c_str();
	}
};

#endif