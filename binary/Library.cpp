#include "Library.h"




Logfile::Logfile(const std::string& filelist)
{

	fs.open(filelist.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);

}

std::string Logfile::loglvl(Level lvl)
{
	switch (lvl)
	{
	case Level::VARNING:
		return " [WARNING] ";
	case Level::INFO:
		return " [INFO] ";
	case Level::ERROR:
		return " [ERROR] ";
	case Level::CERROR:
		return " [C][ERROR] ";
	case Level::RUNING:
		return " [RUNING] ";
	case Level::STOP:
		return " [STOP] ";
	default:
		return " [UNKNOWN] ";
	}

}

std::string Logfile::log(Level lvl, const std::string& msg)
{

	fs << loglvl(lvl) << msg.c_str() << std::endl;

	return 0;
}

Logfile::~Logfile()
{
	fs.close();

}
