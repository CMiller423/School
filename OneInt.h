#pragma once
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class OneInt
{
private:
	int oneInteger;
public:
	OneInt(int param = 0);
	int getOneInteger() const;
	void setOneInteger(int);
	bool isPrime() const;
	string to_string() const;

	//********** overloading mathematical operators ************
	OneInt& operator + (const OneInt& param_rhs);
	OneInt& operator + (int param_rhs);

	OneInt& operator - (const OneInt& param_rhs);
	OneInt& operator * (const OneInt& param_rhs);
	OneInt& operator / (const OneInt& param_rhs);

	double sqareRoot(const OneInt& param_rhs);

	//********** overloading relational operators ************
	bool operator > (const OneInt& param_rhs);
	bool operator == (const OneInt& param_rhs);
	bool operator != (const OneInt& param_rhs);
	bool operator < (const OneInt& param_rhs);

	

	//friend
		//********** friend functions ************
	friend ostream& operator << (ostream& my_cout, const OneInt&);
	friend istream& operator >> (istream& my_cin, OneInt& param_OneInt);
};


/* ******************************************************
	Class constructor
******************************************************* */

OneInt::OneInt(int param)
{
	oneInteger = param;
}

/* ******************************************************
	Accessor & Mutator function for oneInteger
******************************************************* */
int OneInt::getOneInteger() const
{
	return oneInteger;
}

void OneInt::setOneInteger(int param)
{
	oneInteger = param;
}
/* ******************************************************
	isPrime function
******************************************************* */
bool OneInt::isPrime() const
{
	bool return_val = true;
	int sqrt_of_oneInteger = int(sqrt(oneInteger));

	for (int i = 2; i <= sqrt_of_oneInteger && return_val; i++)
		if (oneInteger % i == 0)
			return_val = false;

	return return_val;
}
/* ******************************************************
	to_string function
******************************************************* */
string OneInt::to_string() const
{
	string return_val = std::to_string(oneInteger);
	if (isPrime())
		return_val += " (Prime Number)";
	else
		return_val += " (Not a Prime number)";
	return return_val;
}

/* ******************************************************
	Operloading the + operator
******************************************************* */
OneInt& OneInt::operator + (const OneInt& param_rhs)
{
	OneInt* answer = new OneInt(this->oneInteger + param_rhs.oneInteger);
	return *answer;
}
OneInt& OneInt::operator + (int param_rhs)
{
	OneInt* answer = new OneInt(this->oneInteger + param_rhs);
	return *answer;
}

/* ******************************************************
	Operloading the - operator
******************************************************* */
OneInt& OneInt::operator - (const OneInt& param_rhs)
{
	OneInt* answer = new OneInt;
	answer->oneInteger = this->oneInteger - param_rhs.oneInteger;
	return *answer;
}

/* ******************************************************
	Operloading the * operator
******************************************************* */
OneInt& OneInt::operator * (const OneInt& param_rhs)
{
	OneInt* answer = new OneInt(this->oneInteger * param_rhs.oneInteger);
	return *answer;
}
/* ******************************************************
	Operloading the / operator. Rounds up answer
******************************************************* */
OneInt& OneInt::operator / (const OneInt& param_rhs)
{
	OneInt* answer = new OneInt;
	double divide_answer = static_cast<double>(this->oneInteger) / param_rhs.oneInteger;
	answer->oneInteger = round(divide_answer);
	return *answer;
}
/* ******************************************************
	Square Root Function
******************************************************* */
double OneInt::sqareRoot(const OneInt& param_rhs)
{
	return sqrt(param_rhs.oneInteger);
}
/* ******************************************************
	Operloading the > operator
******************************************************* */
bool OneInt::operator > (const OneInt& param_rhs) //if (var1.>(var2) == true)
{
	bool answer = false;
	if (this->oneInteger > param_rhs.oneInteger)
		answer = true;
	return answer;
}
/* ******************************************************
	Operloading the < operator
******************************************************* */
bool OneInt::operator < (const OneInt& param_rhs) //if (var1.<(var2) == true)
{
	bool answer = false;
	if (this->oneInteger < param_rhs.oneInteger)
		answer = true;
	return answer;
}
/* ******************************************************
	Operloading the == operator
******************************************************* */
bool OneInt::operator == (const OneInt& param_rhs)
{
	bool answer = false;
	if (this->oneInteger == param_rhs.oneInteger)
		answer = true;
	return answer;
}
/* ******************************************************
	Operloading the != operator
******************************************************* */
bool OneInt::operator != (const OneInt& param_rhs)
{
	bool answer = false;
	if (this->oneInteger != param_rhs.oneInteger)
		answer = true;
	return answer;
}

/* **************************************************************
				 F R I E N D     F U N C T I I O N S
		Overloading Stream Insertion (<<) and Stream Extraction ( >>) operators)
****************************************************************/
ostream& operator <<(ostream& my_cout, const OneInt& param_OneInt)
{
	my_cout << param_OneInt.to_string();
	return my_cout;
}

istream& operator >>(istream& my_cin, OneInt& param_OneInt)
{
	my_cin >> param_OneInt.oneInteger;
	return my_cin;
}

