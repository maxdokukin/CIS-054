//
//  Student.h
//  STUDENT
//
//  Created by Max Dokukin on 23/03/2021.
//

#include <string>
using namespace std;

class Student
{
private:
    string name, major;
    int IdNumber;
    double gpa;
    
public:
    // constructors
    Student();  // default constructor
    Student(string n, int id, double g, string m);

    //mutators and accessors
    void setName(string n);
    string getName();
    
    void setIdNumber(int id);
    int  getIdNumber();
    
    void setGpa(double g);
    double getGpa();
    
    void setMajor(string n);
    string getMajor();

};
