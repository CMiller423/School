/*
Author :  Carson Miller
Purpose:  The purpose of this program is to demonstrate the usage of arrays.
          Another purpose of this program is to demonstrate the usage of loops and file structure.

*/


//Include all libraries and class's for program to function
#include <iostream>
#include <string>
#include "PersonNameFileCreator.h"
#include "PersonName.h"

//using standard namespace
using namespace std;

//main fuction
int main()
{
    //Array storing all the names used for this program
    string arr_names[] = { "Adam Burke", "Madeline Kramer", "Scott Gardner",
        "Tonya Lopez", "Christopher Hamilton", "Andrew Mitchell", "Lori Smith" };

    //creats the fil_name variable using type PersonNameFileCreator
    PersonNameFileCreator fil_names("names.txt");


    //loops through the array finding each name in arr_names[]
    for (auto one_name : arr_names)
    {
        //declares first name and last name variables and an integer called leftoff which will log what index we leave off on
        string fname, lname;
       
        //finds the first blank character
        int pos_of_blank = one_name.find_first_of(' ');
        //writes the first name variable as the substring of the whole name from the first character to the position of the blank character
        fname = one_name.substr(0, pos_of_blank);
        //write the last name variable as the substring of the remaining name.
        lname = one_name.substr(pos_of_blank+1);


        //creates onePerson object using fname and lname variables
        PersonName onePerson(fname, lname);
        //take the fil_name object and write its information to a file using the onePerson object
        fil_names.write_to_file(onePerson);
    }

    //return 0 to end the program
    return 0;
}