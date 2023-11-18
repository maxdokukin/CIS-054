//
//  main.cpp
//  RATIONAL NUMBERS
//
//  Created by Max Dokukin on 09/04/2021.

#include "Rational.h"
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

// function prototypes
void initializeNumbers (Rational &, Rational &, Rational &);
void displayNumbers (Rational, Rational, Rational, string);

void printSplitLine();
void printEndLine();
string generateOutputForReport(string op);
string getRationalString(Rational n1, Rational n2, Rational n3);
void displayOperation(Rational, Rational, Rational, string op);


int main(int argc, char* argv[]){

    Rational n1;
    Rational n2;
    Rational n3;

    
    //print header
    printEndLine();
    cout << "|  n1  |  n2  |  n3  |     Operation     |" << endl;
    printSplitLine();
    
    initializeNumbers (n1, n2, n3);
    displayNumbers(n1, n2, n3, "|||||||||||||||");
    printSplitLine();
    printSplitLine();

    
    // Test operator+
    initializeNumbers (n1, n2, n3);
    n1 = n2+n3;
    displayNumbers(n1, n2, n3, "n1 = n2 + n3");

    
    // Test operator+=
    initializeNumbers (n1, n2, n3);
    n1 = n2 += n3;
    displayNumbers(n1, n2, n3, "n1 = n2 += n3");
    
    
    printSplitLine();
    
    // Test operator-
    initializeNumbers (n1, n2, n3);
    n1 = n2 - n3;
    displayNumbers(n1, n2, n3, "n1 = n2 - n3");

    
    // Test operator-=
    initializeNumbers (n1, n2, n3);
    n1 = n2 -= n3;
    displayNumbers(n1, n2, n3, "n1 = n2 -= n3");
    
    
    printSplitLine();
    
    // Test operator*
    initializeNumbers (n1, n2, n3);
    n1 = n2 * n3;
    displayNumbers(n1, n2, n3, "n1 = n2 * n3");
    
    
    // Test operator *=
    initializeNumbers (n1, n2, n3);
    n1 = n2 *= n3;
    displayNumbers(n1, n2, n3, "n1 = n2 *= n3");
    

    printSplitLine();

    // Test operator /
    initializeNumbers (n1, n2, n3);
    n1 = n2 / n3;
    displayNumbers(n1, n2, n3, "n1 = n2 / n3");
    
    
    // Test operator /=
    initializeNumbers (n1, n2, n3);
    n1 = n2 /= n3;
    displayNumbers(n1, n2, n3, "n1 = n2 /= n3");
    
    
    printSplitLine();
    
    //test false condition for == operator
    initializeNumbers (n1, n2, n3);
    string logicalOutput = "n2 == n3 ";
    logicalOutput += (n2 == n3 ? "TRUE" : "FALSE");
    displayNumbers(n1, n2, n3, logicalOutput);

    //test true condition for == operator
    n3 = Rational(3, 4);
    logicalOutput = "n2 == n3 ";
    logicalOutput += (n2 == n3 ? "TRUE" : "FALSE");
    displayNumbers(n1, n2, n3, logicalOutput);
    
    
    printEndLine();

    
//    cout << generateOutputForReport("+") << endl;
//    cout << generateOutputForReport("+=") << endl;
//    cout << generateOutputForReport("-") << endl;
//    cout << generateOutputForReport("-=") << endl;
//    cout << generateOutputForReport("*") << endl;
//    cout << generateOutputForReport("*=") << endl;
//    cout << generateOutputForReport("/") << endl;
//    cout << generateOutputForReport("/=") << endl;


    return 0;
}

// Initialize each of the variables before testing each rational operator
void initializeNumbers (Rational &n1, Rational &n2, Rational &n3){
    
    n1 = Rational ();
    n2 = Rational (3,4);
    n3 = Rational (2,3);
}


void displayNumbers (Rational n1, Rational n2, Rational n3, string msg){
    
    cout << "|" << setw(6) << n1 << "|" << setw(6) << n2 << "|" << setw(6)  << n3 << "|  " << setw(15) << msg << "  |" << endl;
}


void printSplitLine(){
    
    cout << "|------|------|------|-------------------|\n";
}


void printEndLine(){
    
    cout << "+------+------+------+-------------------+\n";
}


string generateOutputForReport(string op){
    
    string output = "         n1     n2     n3\nBEFORE ";
    
    Rational n1;
    Rational n2;
    Rational n3;
    initializeNumbers (n1, n2, n3);
    
    output += getRationalString(n1, n2, n3) + "\nAFTER  ";

    if(!op.compare("+"))
        n1 = n2 + n3;
    
    else if(!op.compare("+="))
        n1 = n2 += n3;
    
    else if(!op.compare("-"))
        n1 = n2 - n3;
    
    else if(!op.compare("-="))
        n1 = n2 -= n3;
    
    else if(!op.compare("*"))
        n1 = n2 * n3;
    
    else if(!op.compare("*="))
        n1 = n2 *= n3;
    
    else if(!op.compare("/"))
        n1 = n2 / n3;
    
    else if(!op.compare("/="))
        n1 = n2 /= n3;
    
    cout << op << endl;
    
    output += getRationalString(n1, n2, n3);
    
    return output;
}


string getRationalString(Rational n1, Rational n2, Rational n3){
    
    string output;
    
    string currentRat = to_string(n1.getNumerator()) + "/" + to_string(n1.getDenominator());

    while(currentRat.length() < 5)
        currentRat = " " + currentRat;
    
    output += currentRat + "  ";

    
    currentRat = to_string(n2.getNumerator()) + "/" + to_string(n2.getDenominator());

    while(currentRat.length() < 5)
        currentRat = " " + currentRat;
    
    output += currentRat + "  ";

    
    currentRat = to_string(n3.getNumerator()) + "/" + to_string(n3.getDenominator());

    while(currentRat.length() < 5)
        currentRat = " " + currentRat;
    
    output += currentRat;

    return output;
}


void displayOperation(Rational o1, Rational o2, Rational res, string op){
    
    string output = "";
    
    output += o1.getAsString() + " " + op + " " + o2.getAsString() + " is " + res.getAsString();
    
    cout << output << endl;
}
