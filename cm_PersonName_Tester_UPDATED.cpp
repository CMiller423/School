/*
Author :  Carson Miller
Purpose:  The purpose of this program is to demonstrate the usage of dynamic memory allocation and pointers.
*/

//includes all libraries and classes for program to function
#include "PersonName.cpp"
#include <iostream>
#include <string>
#include <array>

//using standard namespace
using namespace std;

//function protoyope for the names
void printNames(PersonName arr[], int size);

//main function that drives the program
int main() {

    //declares input variables2
    int input;

    string nameInput;

    PersonName *point;

    //prompts the user for how many students there are
    cout << "How many students are there? (1-5): ";

    //captures the users input
    cin >> input;

    //if the user enters an invalid value prompt the user to enter it again
    while (input < 1 || input > 5) {
        cout << "The number of students must be within the range of 1-5, please try again!" << endl;
        cin >> input;
    }

    //creates the array
    PersonName arr[input];

    //assigns the pointer to the array
    point = arr;

    //for loop to write the data to the array through the pointer.
    for(int i = 0; i < input; i++) {
        //prompts user to enter the first name and writes it to the array
        //i+1 is necessary as the array starts at 0 but the names start at 1
        cout << "Entering data for Name #" << i+1  << endl;
        //this if statment is necisarry as the pointer does not have arithmetic attached to it
        if(i == 0) {
            cout <<"         Enter first name : ";
            cin >> nameInput;
            point->setFi_name(nameInput);
            //prompts the user to enter the last name and writes it to the array
            cout <<"         Enter last name : ";
            cin >> nameInput;
            //stores all the entered information into the first element of the array through the usage of the pointer
            point->setLa_name(nameInput);
        }
        else {
            cout <<"         Enter first name : ";
            cin >> nameInput;
            //procedurally step through the array using the pointer to set the different names.
            (point + i)->setFi_name(nameInput);
            //prompts the user to enter the last name and writes it to the array
            cout <<"         Enter last name : ";
            cin >> nameInput;
            (point + i)->setLa_name(nameInput);
        }
        //prints a blank character to seperate the incoming information for the next name.
        cout << " " << endl;
    }

    //calls printNames function
    printNames(arr, input);
    

    //return 0 to indicate the program has ran successfully
    return 0;
}

//function that takes the array, and the size
void printNames(PersonName arr[], int size) {
    //for loop that starts at the beginning of the array and steps through
    for(int i = 0; i< size; i++) {
        //header for the names, i+1 is necessary as the array starts at 0 but the names start at 1
        cout << "*********   Name #" << i+1 << " *************" << endl;
        cout << arr[i].to_string() << endl;
        cout << "\n";
    }
}