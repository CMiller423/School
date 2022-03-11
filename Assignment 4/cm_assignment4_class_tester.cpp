#include <iostream>
#include <string>
#include <cctype>
using namespace std;
#include "Asn4_String.h"
string get_lowercase_version(const string &param);
string get_only_alpha(const string& param);
int main()
{
    //creates strings to add to the later cout statements
    string it_is_palindrome = " (Is a palindrome)";
    string it_isnt_palindrome = " (Not a palindrome)";

    //string array containing potential palindromes
    string arr_test[] = {
        "Able was I ere I saw Elba",
        "Madam Im Adam",
		"Madam I'm Adam",
        "Who said this",
        "geaeg" , "GeAag", "A", "Aa",""};

    for (auto one_test : arr_test)
    {
        //creates test_str oject
        Asn4_String test_str(one_test);

        //if the string is a palindrome
        if(test_str.is_palindrome(test_str.get_string())) {
            cout << "class_string = " << test_str << it_is_palindrome << endl;
        }
        else {
            cout << "class_string = " << test_str << it_isnt_palindrome << endl;
        }
        
        //creates lower case test string with the get lowercase function
		string test_str_lc = get_lowercase_version(one_test);
        //sets the new lower case string as the string to be tested as a palindrome
		test_str.set_string(test_str_lc);

        //if the lower case string is a palindrome
        if(test_str.is_palindrome(test_str_lc)) {
            cout << "Lower case version of the string :" << test_str_lc << it_is_palindrome << endl;
        }
        else {
            cout << "Lower case version of the string :" << test_str_lc << it_isnt_palindrome << endl;
        }
		
        //creates only alphabetic string with the get get only alpha function
		string test_str_only_alpha = get_only_alpha(one_test);
        //sets the new lonly alphabetic string as the string to be tested as a palindrome
		test_str.set_string(test_str_only_alpha);

        if(test_str.is_palindrome(test_str_only_alpha)) {
            cout << "String with only alphabets :" << test_str_only_alpha << it_is_palindrome << endl;
        }
		else {
            cout << "String with only alphabets :" << test_str_only_alpha << it_isnt_palindrome << endl;
        }

		cout << "--------------------------------\n";
    }
    return 0;
}

string get_only_alpha(const string& param)
{
    //gets the lowercase version of the input parameter
    string lower_param = get_lowercase_version(param);
    string ret_val = "";

    //steps through the now lowercase parameter
     for(auto character : lower_param) {
        //if the character isnt alphabetic or is blank then ingore it and continue
         if((!isalpha(character)) || isblank(character)) {
             continue;
         }
         //else write the character to the return value
         else {
             ret_val += character;
         }
     }
	return ret_val;
}

string get_lowercase_version(const string &param)
{
    string return_value = "";
    //steps through the parameter
    for(auto character : param) {
        //takes the current character and makes it lowercase then adds it to the return value.
        return_value += tolower(character);
    }
	return return_value;
}


