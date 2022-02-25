//this file was provided by the proffessor
//includes class for program to function
#include "PersonName.h"

//creates strip fuction, takes string as a parameter
string PersonName::strip(string param)
{
    //creates blank string called return string
    string return_str = "";
    //if the passed in strings length is greater than 0
    if (param.length() > 0)
    {
        //creates integer called first non blank
        int first_nonblank;
        //assigns the first non blank variable to the returned result of "param.find_first_not_of(' ')"
        first_nonblank = param.find_first_not_of(' ');
        //if first non blank is greater than -1
        if (first_nonblank > -1)
        {
            //declares last non blank and number of characters varibles as integers
            int last_nonblank, num_char;
            //last non blank is assiged the returned result of "param.find_last_not_of(' ')"
            last_nonblank = param.find_last_not_of(' ');
            //number of characters set to last non blank minus first non blank plus one
            num_char = last_nonblank - first_nonblank + 1;
            //sets the return string to the substring of the passed in string from first non blank to the number of characters
            return_str = param.substr(first_nonblank, num_char);
        }
    }
    //if the return string is blank
    if (return_str == "")
        //set return string to "-n/a-"
        return_str = "-n/a-";
    //returns the variable
    return return_str;
}

//creates change case function, takes a string as a parameter
string PersonName::changeCase(string param)
{
    //creates blank string called return string
    string return_str = "";
    //if the passed in string is not equal to "-n/a-"
    if (param != "-n/a-")
    {
        //set the return string to the first character that was made into upercase
        return_str = toupper(param[0]);
        //loops through the remaining string
        for (int i = 1; i < param.length(); i++)
            //adds the rest of the string to the return string as lower case one character at a time
            return_str += tolower(param[i]);
    }
    //if the passed in string IS equal to "-n/a-"
    else
        //set the return string to "-n/a-"
        return_str = "-n/a-";
    //returns the return string
    return return_str;
}

//creates the PersonName constructor, takes first name and last name as parameters
PersonName::PersonName(string _fi_name, string _la_name)
{
    //strips the first name and last name varaibles and stores them
    fi_name = strip(_fi_name);
    la_name = strip(_la_name);
    //makes sure the the first name and lastname only has uppercase characters in the bigginging. ex. "Carson Miller" and not "CARSON MILLER"
    fi_name = changeCase(fi_name);
    la_name = changeCase(la_name);
}

//creates the get mail name function, this function is constant
string PersonName::getMailName() const
{
    //returns the first name and lastname formatted like it would when you see your name in the mail. ex. "Carson Miller"
    return fi_name + " " + la_name;
}

//creates the get directory name function, this function is constant
string PersonName::getDirectoryName() const
{
    //returns the last name and first name formmated like it would when you see it in a directory. ex. "Miller, Carson"
    return la_name + ", " + fi_name;
}

//creates to string function, this function is constant
string PersonName::to_string() const
{
    //declares blanks string as return string
    string return_str = "";
    //adds formmatting to the names of the people
    return_str =  "First Name     = " + fi_name + "\n";
    return_str += "Last Name      = " + la_name + "\n";
    return_str += "Mail Name      = " + getMailName() + "\n";
    return_str += "Directory Name = " + getDirectoryName();
    
    //returns the return string
    return return_str;
}
