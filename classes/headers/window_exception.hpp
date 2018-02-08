#ifndef WINDOW_EXCEPTION_H
#define WINDOW_EXCEPTION_H

#include <string>


class window_exception {
	public:
		std::string getMessage(){return message;}
		window_exception(std::string msg = ""):message(msg){}
	private:
		std::string message;
};

#endif