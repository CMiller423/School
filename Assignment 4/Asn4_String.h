#pragma once
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
class Asn4_String
{
private:
	string class_string;
	bool check_pd(string param, int _start, int _end) const;
public:
	Asn4_String(string = "-");
	void set_string(string param);
	string get_string() const;
	bool is_palindrome(string) const;

	friend ostream& operator <<(ostream& my_cout, const Asn4_String& param);
};


Asn4_String::Asn4_String(string param)
{
    set_string(param);
}

ostream& operator <<(ostream& my_cout, const Asn4_String& param)
{
	//gets the string from the object and writes it to my_cout
	my_cout << param.get_string();
	return my_cout;
}

void Asn4_String::set_string(string param)
{
    class_string = param;
}

string Asn4_String::get_string() const
{
    return class_string;
}

bool Asn4_String::is_palindrome(string param) const
{
    return check_pd(param, 0, param.size() - 1);
}

bool Asn4_String::check_pd(string param, int start_index, int end_index) const
{
	//if the start index and the end index are equal then that means the input parameter is just one character, therefore it must be a palindrome
	if(start_index == end_index) {
		return true;
	}

	//if the starting index and the ending index aren't the same then it cannot be a palindrome
	if(param[start_index] != param[end_index]) {
		return false;
	}

	//if the starting index is less than the ending index + 1, then it means it hasnt reached the desired outcome yet.
	if(start_index < end_index + 1) {
		//passes the new substring of the paramter starting + 1 and ending -1
		return check_pd(param, start_index + 1, end_index - 1);
	}

	//returns true as a base case.
	return true;
}