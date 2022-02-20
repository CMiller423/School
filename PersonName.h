//includes all libraries needed to function
#pragma once
#include <iostream>
#include <string>
//using standard namespace
using namespace std;

//declares PersonName class
class PersonName
{

//declares private variables and function prototypes
private:
	string fi_name, la_name;
	string strip(string param);
	string changeCase(string);
//declares public function prototypes	
public:
	PersonName(string _fi_name = "-n/a-", string _la_name = "-n/a-");
	void setFi_name(string param);
	void setLa_name(string param);
	string getMailName() const;
	string getDirectoryName() const;
	string to_string() const;
};