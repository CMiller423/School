//includes header file needed for program to function
#include "PersonName.h"

//declares strip function taking a string as a parameter
string PersonName::strip(string param)
{
    //declares return string
    string return_str = "";
    //if the passed in strings length is greater than zero
    if (param.length() > 0)
    {
        //creates variable of first_nonblank of type unsigned
        unsigned first_nonblank;
        //finds the first character that isnt a space.
        first_nonblank = param.find_first_not_of(' ');
        //if the returned value is greater than -1
        if (first_nonblank > -1)
        {
            //declares last_nonblank and num_char of type unsigned
            unsigned last_nonblank, num_char;
            //finds last character that isnt a space
            last_nonblank = param.find_last_not_of(' ');
            //takes the number of characters from the last non blank to the first non blank +1
            num_char = last_nonblank - first_nonblank + 1;
            //takes the substring of the first non blank to that number of characters.
            return_str = param.substr(first_nonblank, num_char);
        }
    }
    //if the return string is still blank
    if (return_str == "")
        //set the return string to say "-n/a-"
        return_str = "-n/a-";
    //return the variable
    return return_str;
}

//declares change case function that takes a string parameter
string PersonName::changeCase(string param)
{   
    //declares return string
    string return_str = "";
    //if the parameter isnt "-n/a-"
    if (param != "-n/a-")
    {   
        //take the first character of the passed in string and capitalize it
        return_str = toupper(param[0]);
        //loop through the remaning characters in that parameter and make them lower case.
        for (int i = 1; i < param.length(); i++)
            return_str += tolower(param[i]);
    }
    //else just keep the return string as "-n/a-"
    else
        return_str = "-n/a-";

    //return the string
    return return_str;
}

//declares person name constructor that takes first name and last name as variables
PersonName::PersonName(string _fi_name, string _la_name)
{
    //strip and format the first and last name variables
    fi_name = strip(_fi_name);
    la_name = strip(_la_name);
    fi_name = changeCase(fi_name);
    la_name = changeCase(la_name);
}

//declares set first name function taking a string as a parameter
void PersonName::setFi_name(string param)
{
    //set the first name variable to the parameter
    fi_name = param;
}

//declares set last name function taking a string as a parameter
void PersonName::setLa_name(string param)
{
    //set the last name variable to the parameter
    la_name = param;
}
//declares get mail name function
string PersonName::getMailName() const
{
    //returns the first name and last name seperated by a space.
    return fi_name + " " + la_name;
}

//declares get directory name function
string PersonName::getDirectoryName() const
{   
    //returns the last name and first name seperated by a comma then a space.
    return la_name + ", " + fi_name;
}

//decleares the to string function
string PersonName::to_string() const
{
    //declares blank return string
    string return_str = "";
    //concats all of the proper information to display for the program
    return_str =  "First Name     = " + fi_name + "\n";
    return_str += "Last Name      = " + la_name + "\n";
    return_str += "Mail Name      = " + getMailName() + "\n";
    return_str += "Directory Name = " + getDirectoryName();
    //return the string
    return return_str;
}
