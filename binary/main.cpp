#include <iostream>
#include "Library.h"



int main()
{
	Logfile filelog("test.txt");

	filelog.log(Level::ERROR, "Testovaci msg.");



	return 0;
}
