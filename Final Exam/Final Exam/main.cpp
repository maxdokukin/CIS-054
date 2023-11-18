//
//  main.cpp
//  Final Exam
//
//  Created by Max on 17/05/2021.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//string functions//
string getString(string compText);
string upper(string s);


/**
 *Searches for the name in the file and records index if name was found
 */
void searchFileForName(string filenames, string targetNameUpper, int * boyIndex, int * girlIndex);

void printResults(string targetName, int boyIndex, int girlIndex);

int main(int argc, const char * argv[]) {

    //set filename
    string filename = "/Users/xewe/Documents/Programming/CIS-054/Final Exam/Final Exam/FirstNames.txt";
    
    //get name for search
    string targetName = getString("Enter name for search : ");

    //indexes for found boy and girl names
    int boyIndex = -1, girlIndex = -1;
    
    //perform search
    searchFileForName(filename, upper(targetName), &boyIndex, &girlIndex);
    
    //print results
    printResults(targetName, ++boyIndex, ++girlIndex);
}


void searchFileForName(string filename, string targetNameUpper, int * boyIndex, int * girlIndex){
    
    ifstream names(filename.c_str()); //open file
    
    if(!names){ //if file was not open
        
        cout << "File can't be opened!" << endl;
        return;
    }
    
    string curLine;
    
    for(int i = 0; getline (names, curLine); i++){ //iterate through each line
        
        curLine = upper(curLine);
        
        if(curLine.length() < 2) //if line has no text skip it
            continue;
        
        if((*boyIndex) == -1 && (curLine).find(targetNameUpper + " ") == 0) //boy name was found
            (*boyIndex) = i;
            
        else if((*girlIndex) == -1 && curLine.find(" " + targetNameUpper + "\r") > 0 && curLine.find(" " + targetNameUpper + "\r") < 128) //girl name was found
            (*girlIndex) = i;
    }
    
    names.close(); //close file
}

void printResults(string targetName, int boyIndex, int girlIndex){

    if(boyIndex) //if boy name was found
        cout << setw(60) << left << ("| Male name " + targetName + " is #" + to_string(boyIndex) + " in the popular list.") << "|" << endl;
    else
        cout << "| There is no male name " << setw(36) << left << targetName + "." << "|" << endl;

    cout << "|-----------------------------------------------------------|" << endl;

    if(girlIndex) //if girl name was found
        cout << setw(60) << left << ("| Female name " + targetName + " is #" + to_string(girlIndex) + " in the popular list.") << "|" << endl;

    else
        cout << "| There is no female name " << setw(34) << left << targetName + "." << "|" << endl;

    cout << "-------------------------------------------------------------" << endl;
}

//inputs string from user
string getString(string compText){
    
    cout << "-------------------------------------------------------------\n| " << compText;
    
    string s;
    
    cin >> s;

    cout << "|-----------------------------------------------------------|" << endl;

    return s;
}


//makes string uppercase
string upper(string s){
    
    string r = "";
    
    for(int i = 0; i < s.length(); i++)
        r += toupper(s.at(i));
    
    return r;
}
