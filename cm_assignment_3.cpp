#include <iostream>
#include <iomanip>
#include "Rational.h"

using namespace std;

int main()
{
	Rational rational_1(5, 6);
	Rational rational_2;
	Rational rational_Add, rational_Sub, rational_Mult, rational_Divide;
    cout << "Enter numerator and denominator separated by a space : ";

	cin >> rational_2;

	rational_Add = rational_1 + rational_2;
	rational_Sub = rational_1 - rational_2;
	rational_Mult = rational_1 * rational_2;
	rational_Divide = rational_1 / rational_2;

	cout << "rational_1 : " << rational_1 << " = " << setprecision(2) << rational_1.print_result()<< endl
		<< "rational_2 : " << rational_2 << " = " <<  setprecision(2) << rational_2.print_result()<< endl
		<< "rational_Add : " << rational_Add << " = " << setprecision(3) << rational_Add.print_result() << endl
		<< "rational_Sub : " << rational_Sub << " = " << setprecision(3) << rational_Sub.print_result()<< endl
		<< "rational_Mult : " << rational_Mult << " = " << setprecision(3) << rational_Mult.print_result()<< endl
		<< "rational_Divide : " << rational_Divide << " = " << setprecision(2) << rational_Divide.print_result()<< endl;


	return 0;
}