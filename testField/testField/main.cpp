//
//  main.cpp
//  testField
//
//  Created by Max on 17/05/2021.
//

#include <iostream>

using namespace std;




class A{
    
    protected: int p = 6;
        
    public:
        A(){};
        
        
        
    protected: void print(){
        
        cout << "print" << endl;
    }
};


class B : public A{
    
public:
    B(){}
    
};

int main(int argc, const char * argv[]) {
    
    B *b = new B();
    
    b->print();
    
    int c = b->p;
        
    return 0;
}
