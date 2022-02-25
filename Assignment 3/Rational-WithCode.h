#include <iostream>
#include <iomanip>

using namespace std;

class Rational 
{
private:
	int numerator;
	int denominator;
public:

	Rational(int num, int denom);
	Rational();
	string to_string() const;
	int greatest_common_denom(int denom1, int denom2);
	int least_common_multiple(int a, int b);

    //********** overloading mathematical operators ************
	Rational& operator + (const Rational& param);
	Rational& operator + (int param);

	Rational& operator - (const Rational& param);
	Rational& operator * (const Rational& param);
	Rational& operator / (const Rational& param);

	//********** overloading relational operators ************
	bool operator > (const Rational& param);
	bool operator == (const Rational& param);
	bool operator != (const Rational& param);
	bool operator < (const Rational& param);

	

	//friend
		//********** friend functions ************
	friend ostream& operator << (ostream& my_cout, const Rational&);
	friend istream& operator >> (istream& my_cin, Rational& param);

	//print the resulting fraction as a number.
	double print_result();
};


Rational::Rational() {
	numerator = 0;
	denominator = 0;
}

Rational::Rational(int num, int denom) {
	numerator = num;
	denominator = denom;
}

/* ******************************************************
	to_string function
******************************************************* */
string Rational::to_string() const
{
	string return_val = std::to_string(numerator);
	return_val += "/";
	return_val += std::to_string(denominator);
	return return_val;
}

int Rational::greatest_common_denom(int denom1, int denom2) {
	if (denom1 == 0) {
		return denom2;
	}
	return greatest_common_denom(denom2 % denom1, denom1);
}

int Rational::least_common_multiple(int denom1, int denom2) {
	return (denom1 * denom2) / greatest_common_denom(denom1, denom2);
}

/* ******************************************************
	Operloading the + operator
******************************************************* */
Rational& Rational::operator + (const Rational& param)
{
	int least_common_denom = least_common_multiple(this->denominator, param.denominator);
	int object_numerator = this->numerator;
	int param_numerator = param.numerator;

	object_numerator *= (least_common_denom / this->denominator);
	param_numerator *= (least_common_denom / param.denominator);

	int sum = object_numerator + param_numerator;

	Rational* answer = new Rational(sum, least_common_denom);
	return *answer;
}

/* ******************************************************
	Operloading the - operator
******************************************************* */
Rational& Rational::operator - (const Rational& param)
{
	int least_common_denom = least_common_multiple(this->denominator, param.denominator);
	int object_numerator = this->numerator;
	int param_numerator = param.numerator;

	object_numerator *= (least_common_denom / this->denominator);
	param_numerator *= (least_common_denom / param.denominator);

	int sum = object_numerator - param_numerator;

	Rational* answer = new Rational(sum, least_common_denom);
	return *answer;
}

/* ******************************************************
	Operloading the * operator
******************************************************* */
Rational& Rational::operator * (const Rational& param)
{
	Rational* answer = new Rational((this->numerator * param.numerator), (this->denominator * param.denominator));
	return *answer;
}

/* ******************************************************
	Operloading the / operator
******************************************************* */
Rational& Rational::operator / (const Rational& param)
{

	Rational* answer = new Rational((this->numerator * param.denominator), (this->denominator * param.numerator));
	return *answer;
}


/* **************************************************************
				 F R I E N D     F U N C T I I O N S
		Overloading Stream Insertion (<<) and Stream Extraction ( >>) operators)
****************************************************************/
ostream& operator <<(ostream& my_cout, const Rational& param)
{
	my_cout << param.to_string();
	return my_cout;
}

istream& operator >>(istream& my_cin, Rational& param)
{
	my_cin >> param.numerator;
	my_cin >> param.denominator;

	if (param.numerator == 0 && param.denominator == 0) {
		while (param.numerator == 0 && param.denominator == 0) {
			cout << "Both Numerator and Denominator cannot be zero! Please enter new numerator and denominator seperated by a space!" << endl;
			my_cin >> param.numerator;
			my_cin >> param.denominator;
		}
	}
	else {
		while (param.numerator == 0) {
			cout << "Numerator cannot be zero! Please enter a new numerator!" << endl;
			my_cin >> param.numerator;
		}


		while (param.denominator == 0) {
			cout << "Denominator cannot be zero! Please enter a new denominatior!" << endl;
			my_cin >> param.denominator;
		}

	}

	return my_cin;
}

double Rational::print_result() {
	return static_cast<double> (this->numerator) / this->denominator;
}

