#pragma once
/**
* Toto je libka k inicializaci třídy
* A k NASTAVENÍ urovně logu jako je enum
* a mělo by být možnost nastavit maximálni velikost logu
**/
#ifndef LIBRARY_H			// definice hlavičkového souboru
#define LIBRARY_H			// definice hlavičkového souboru
#include <string>			// kvuli std::string
#include <fstream>			// std::fstream // fstream::open // fstream::close

/**
* Nastavení urovně logovani enum začíná na 0 tedy Warning
* Hodnota 1 je tedy Info úroveň
* Hodn. 2 je tedy ERROR slouží pro úroveň chyb
* Critical ERROR je CEROR značí kritickou chybu
* 4 je úroveň běhu tedy bude značit že smyčka nebo thread běží
* a další je 5 že provedený smyčka nebo thread byly ukončeny
**/
enum Level													// enum Level
{
	VARNING,		// úroveń varování
	INFO,			// úroveň informace
	ERROR,			// uroveň chyby
	CERROR,			// úroveň kritické chyby
	RUNING,			// úroveň běhu
	STOP			// úroveň zastavení
};


class Logfile												// Třída LogFile
{
public:														// Veřejný přístup
	
	/**
	* Tento konstruktor nastavuje cestu a jmeno k souboru 
	* příklad je "patch/file"
	*/
	Logfile(const std::string &filelist);					// Konstruktor 

	/**
	* Tato funkce nastavuje level
	* a mění ho na řetězec stringu
	* vrací řetězec string
	*/
	std::string loglvl(Level lvl);

	/**
	* Tato funkce získá string z fuunkce loglv
	* která nastaví řetězec stringu
	* pote se ziská konstatntí řetězec msg (mesenger)
	* A vypíše se do fstream(souboru) nakonec souboru
	*/
	std::string log(Level lvl,const std::string& msg);


	/**
	* Destruktor nastavje uzavření souboru (close)
	*/
	~Logfile();												// Destruktor



private:													// soukromí ppřístup

	std::fstream fs;






};















#endif // SIMPLE_LOGGING_LIBBRARY_H