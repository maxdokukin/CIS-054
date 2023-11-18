//
//  Rational.cpp
//  RATIONAL NUMBERS
//
//  Created by Max on 09/04/2021.
//

#include <iostream>
#include "Rational.h"
using namespace std;

// By using the default parameter settings in Rational.h, this
// constructor also provides the default constructor Rational()
Rational::Rational (int num, int denom)
{
    setRational(num,denom);   // set numerator and denominator, reduce fraction, fix the sign
}

// Helper function to fix a zero denominator and fix the sign if denominator is negative
// setRational uses the LCD function to reduce the fraction to the lowest common denominator
Rational Rational::setRational (int n, int d) // helper function
{
    numerator = n;
    denominator = d;

    // if denominator == 0 then set it = 1
    if (denominator == 0)
        denominator = 1;

    if ( denominator < 0 ) // if denominator is neg, multiply num and denom by -1
    {
        numerator = -numerator;     // fix sign of numerator +/-
        denominator = -denominator; // denominator always +
    }

    int lcd = LCD(numerator, denominator);
    if (denominator != 0)
    {
        numerator /= lcd;
        denominator /= lcd;
    }
    return *this;   // return a pointer to the current object
}

int Rational::getDenominator(){
    
    return denominator;
}

int Rational::getNumerator(){
    
    return numerator;
}

// find the lowest common divisor using a recursive function
int Rational::LCD(int v1, int v2)
{
    if (v2==0) return v1;
    else return LCD (v2, v1%v2);
}

string Rational::getAsString(){
    
    return to_string(numerator) + '/' + to_string(denominator);
}


// operator+ method
Rational Rational::operator+ (Rational right)
{
    // create local (temporary) variables
    int newNumerator;
    int newDenominator;

    // compute the result and save in the local variables
    // the current object's numerator and denominator are not changed
    newNumerator = numerator*right.denominator + right.numerator*denominator;
    newDenominator = denominator * right.denominator;

    // create a new Rational object with the result and return it
    return Rational(newNumerator, newDenominator);
}


// operator+= method
Rational Rational::operator+= (Rational right)
{
    // the current object is updated with the result of the +=
    numerator = numerator*right.denominator + right.numerator*denominator;
    denominator = denominator * right.denominator;

    // fix the sign, reduce the fraction and return the current object
    return setRational(numerator, denominator);
}

// the operator- method does the same thing as the add method
Rational Rational::operator- (Rational right)
{
    // create local (temporary) variables
    int newNumerator;
    int newDenominator;

    // compute the result and save in the local variables
    // the current object's numerator and denominator are not changed
    newNumerator = numerator*right.denominator - right.numerator*denominator;
    newDenominator = denominator * right.denominator;

    // create a new Rational object with the result and return it
    return Rational(newNumerator, newDenominator);
}

Rational Rational::operator-= (Rational right)
{
    // the current object is updated with the result of the -=
    numerator = numerator*right.denominator - right.numerator*denominator;
    denominator = denominator * right.denominator;

    // fix the sign, reduce the fraction and return the current object
    return setRational(numerator, denominator);
}

Rational Rational::operator* (Rational right){
    
    return Rational(numerator * right.numerator, denominator * right.denominator);
}


Rational Rational::operator*= (Rational right){
    
    return setRational(numerator * right.numerator, denominator * right.denominator);
}


Rational Rational::operator/ (Rational right){
    
    return Rational(numerator * right.denominator, denominator * right.numerator);
}


Rational Rational::operator/= (Rational right){
    
    return setRational(numerator * right.denominator, denominator * right.numerator);
}


Rational Rational::operator== (Rational right){
    
    return denominator == right.denominator && numerator == right.numerator;
}


Rational::operator double() const // convert Rational to double and return
{
    return double(numerator) / double(denominator);
}

// Display a Rational number using the display() member method
void Rational::display()
{
    cout << numerator << '/' << denominator;
}

// Display a Rational number using << and a friend function.
// Friend functions are not part of the class and their code must be
// declared outside of the class with no :: Scope Resolution Operator.
// All function arguments must have their class defined

//changed this function so it can give a nice formatted output
ostream &operator<< (ostream &out, Rational const &r){
    
    string num = to_string(r.numerator);
    string den = to_string(r.denominator);
    string formatted = num + '/' + den;
    
    out << formatted;
    
    return out;
}

