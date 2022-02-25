//this file was provided by the proffessor
#pragma once //not entirely sure what this means but from my understanding 
			 //it seems like it is used to reduce build times by only calling the libraries once even after building many times?
//includes libraries for program to function
#include <iostream>
#include <string>

//using standard namespace
using namespace std;

//creates PersonName class
class PersonName
{

//creates private variables and function prototypes
private:
	//creates first name and last name variables
	string fi_name, la_name;
	//creates strip function prototype which takes a string as a parameter
	string strip(string param);
	//creates change case function prototype which takes a string as a parameter
	string changeCase(string);
//creates public function prototypes
public:
	//creates Person Name constructor that contains "-n/a-" as both the first name and last name parameters
	PersonName(string _fi_name = "-n/a-", string _la_name = "-n/a-");
	//creates get mail name constant function prototype
	string getMailName() const;
	//creates get directory name constant function prototype
	string getDirectoryName() const;
	//creates to string constant function prototype
	string to_string() const;

};

