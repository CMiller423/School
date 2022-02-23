#include <iostream>
using namespace std;
#include "OneInt.h"

//feel free to change the values around to test various outcomes.
int main()
{
	//creates objects value 1 and value 2.
	OneInt val1= 5;
	OneInt val2 = 15;

	//prints 1 if true 0 if false
	cout << (val1 !=val2) << endl;
	cout << (val1 < val2) << endl;

	//prints the square root of the number given. function must be called on an object as the function cannot be declared as static.awa
	cout << val2.sqareRoot(val2);
	return 0;
}