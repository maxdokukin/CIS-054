

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

////////////// Person class Definition /////////////////
class Person {

protected:
    char Name[20];

public:
    Person (const char* n){
        
        strcpy(Name, n);
    }
    
    virtual void print() const{
        
        cout << "Person:  " << Name << endl;
    }
};

///////////// Student class Definition //////////////
class Student : public Person  {

private:
    int    units;
    
public:
    Student (const char* n, int u) : Person ( n){
        
        units = u;
    }
    
    virtual void print() const{
        
        cout << left << setw(10) << "Student" << "|" <<
                left << setw(30) << Name << "|" <<
                left << setw(10) << "Units: " <<
                left << setw(10) << units << "|" <<
                right << setw(21) << "|" << endl;
    }
};

//////////// Teacher class Definition /////////////////
class Teacher : public Person  {

private:
        int numberOfStudents;
        int numberOfClasses;

public:
        Teacher (const char* n, int s, int c) : Person ( n){
            
            numberOfStudents = s;
            numberOfClasses = c;
        }
    
        virtual void print() const{
            
            cout << left << setw(10) << "Teacher" << "|" <<
                    left << setw(30) << Name << "|" <<
                    left << setw(10) << "Students: " <<
                    left << setw(10) << numberOfStudents << "|" <<
                    left << setw(10) << "Classes: " <<
                    left << setw(10) << numberOfClasses << "|" << endl;
        }
};


//////////// Employee class Definition /////////////////
class Employee : public Person{
    
private:
        int  EmpNo;
        double Hours;
        double PayRate;
    
public:
    Employee (const char* n, int id, double h, double pr) : Person ( n){
        
        EmpNo = id;
        Hours = h;
        PayRate = pr;
    }
    
    virtual void print() const{
        
        cout << left << setw(10) << "Employee" << "|" <<
                left << setw(30) << Name << "|" <<
                left << setw(10) << "Pay:" << "$" <<
                left << setw(9) << computePayCheck() << "|" <<
                right << setw(21) << "|" << endl;
    }
    
private:
    double computePayCheck() const{
        
        return Hours * PayRate;
    }
};



/////////// main program ///////////////////////
int main(int argc, char* argv[]){

    Student s1("Joe Williams", 12);
    Student s2("Mary Smith  ", 9);
    Student s3("Tam  Nguyen ", 10);
    Student s4("Jose Chavez ", 11);
    
    Teacher t1("Dan McElroy ", 28, 3);
    Teacher t3("Fred Jones  ", 18, 2);
    
    Employee e1("Mikhail Abramov", 0, 60, 15);
    Employee e2("Vyacheslav Matuzko", 1, 10, 150);
    Employee e3("Vladimir Putin", 2, 365, 1000000);

    
    Person *List[] = { &t1, &s2, &s3, &s4, &s2, &t3, &e1, &e2, &e3};
    int SizeOfList = sizeof(List)/sizeof(Person*);

    cout << "+----------+------------------------------+--------------------+--------------------+" << endl;

    for (int i=0; i<SizeOfList; i++){
    
        cout << "|";
        List[i]->print();
        
        if(i + 1 < SizeOfList)
        cout << "|----------+------------------------------+--------------------+--------------------|" << endl;
    }
    
    cout << "+----------+------------------------------+--------------------+--------------------+" << endl;

    return 0;
}
