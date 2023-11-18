//
//  main.cpp
//  STUDENT
//
//  Created by Max Dokukin on 23/03/2021.
//

#include <iostream>
#include <iomanip>

#include "Student.h"


using namespace std;


void printStudentList(Student *students, int studentNum);
double calculateAverageGPA(Student *students, int studentNum);
void printGPA(double GPA);


Student CIS054[] = {
    Student ("Maxim Dokukin", 12345, 3.97, "Computer Science"),
    Student ("11 Joe Williams", 4466536, 63.4, "11 subjects"),
    Student ("Sally Washington", 55458, 3.7, "Management"),
    Student ("Fred MacIntosh", 66587, 2.9, "Buisness"),
    Student ("Jose De La Cruz", 67892, 3.5, "Biology"),
    Student ("Dan McElroy", 77777, 4.0, "Electrical engeneering"),
    Student ("Kirill Petrov", 66666, 3.97, "Nuclear Science")
};


int main(int argc, char* argv[]){
    
    int NumberOfStudents = sizeof(CIS054)/sizeof(Student);

    printStudentList(CIS054, NumberOfStudents);
    
    printGPA(calculateAverageGPA(CIS054, NumberOfStudents));
    
    return 0;
}


void printStudentList(Student *students, int studentNum){
    
    cout << left << "+-----------------------------------------------------------------------------+" << endl <<
        setw(12) << "| ID" <<
        setw(27) << "| Name" <<
        setw(32) << "| Major" <<
        setw(7) << "| GPA" <<
        "|" <<
        endl <<
        "|===========|==========================|===============================|======|" <<
        endl;
    
    for (int i = 0; i < studentNum; i++)
        cout << left <<
            "| " << std::setw(10) << students[i].getIdNumber() <<
            "| " << std::setw(25)<< students[i].getName() <<
            "| " << std::setw(30) << students[i].getMajor() <<
            "| " << std::setw(5) << students[i].getGpa() <<
            "| " << endl;

    cout << left << "+-----------------------------------------------------------------------------+"
    << endl;
}


double calculateAverageGPA(Student *students, int studentNum){
    
    double total = 0;
    int undefinedGpaCount = 0;
    
    for (int i = 0; i < studentNum; i++)
        if(students[i].getGpa() >= 0)   //if gpa is ok value
            total += students[i].getGpa();
        else
            undefinedGpaCount++;
    
    return total / (studentNum - undefinedGpaCount); //subtract undefined gpa count
}


void printGPA(double GPA){
    
    std::cout << std::setprecision(2) << std::fixed;
    
    cout << "| The average GPA of all the students is : " << GPA << right << setw(32) << "|"
    << endl <<
    "+-----------------------------------------------------------------------------+"
    << endl;
}
