#pragma once
#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>

enum Level {
	VARNING,
	INFO,
	ERROR,
	RUNING,
	STOP
};

class Log
{
public:

	Log(Level lvl,const std::string& msg);



	~Log();



private:




};















#endif // SIMPLE_LOGGING_LIBBRARY_H