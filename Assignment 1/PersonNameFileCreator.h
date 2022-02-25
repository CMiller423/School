//Created by Carson Miller for CIS230 Assignment 1
//includes all libraries and class's for program to function
#include <iostream>
#include <fstream>
#include <string>
#include "PersonName.h"
#include "PersonName.cpp"

//using standard namespace
using namespace std;

//creates the PersonNameFileCreator class
class PersonNameFileCreator {
    //creates fil_data object of type ofstream and private to this class
    private:
        ofstream fil_data;
    
    //public variables to be used throughout the program
    public: 
        //destructor to close the fil_data object
        ~PersonNameFileCreator() {
            fil_data.close();
        }
        //constructor to create the fil_data ojbect using the passed in file name
        PersonNameFileCreator(string filename) {
            fil_data.open(filename);
        }
        //write to file function containing the person name object
        void write_to_file(const PersonName& param_obj) {
           //writes the directory name of the PersonName object to the file
           fil_data << param_obj.getDirectoryName() << endl;
        }
         
}; 