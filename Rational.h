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
