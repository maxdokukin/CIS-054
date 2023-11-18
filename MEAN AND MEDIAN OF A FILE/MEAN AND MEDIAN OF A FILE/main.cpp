//
//  main.cpp
//  MEAN AND MEDIAN OF A FILE
//
//  Created by Max Dokukin on 30/04/2021.
//

#include <iostream>
#include <fstream>
using namespace std;

#define MAX_ACCOUNT_NUM 4096 //maximum number of lines in one file


double * readBalanceFile(string filename, int * elCount); //reads file, extracts numbers to array, counts number of elements

double computeMean(double * data, int elCount);
double computeMedian(double * data, int elCount);

void printTable(double mean1, double median1, double mean2, double median2);


int main(int argc, const char * argv[]) {
    
    int elCount1; //file 1 element count
    double * balances1 = readBalanceFile("/Users/xewe/Documents/Programming/CIS-054/MEAN AND MEDIAN OF A FILE/MEAN AND MEDIAN OF A FILE/Balances-1.txt", &elCount1); //array of nubers of file 1
    
    int elCount2; //file 2 element count
    double * balances2 = readBalanceFile("/Users/xewe/Documents/Programming/CIS-054/MEAN AND MEDIAN OF A FILE/MEAN AND MEDIAN OF A FILE/Balances-2.txt", &elCount2); //array of nubers of file 2
    
    printTable(computeMean(balances1, elCount1), computeMedian(balances1, elCount1), computeMean(balances2, elCount2), computeMedian(balances2, elCount2));
    
    delete [] balances1; //delete after used
    delete [] balances2;

    return 0;
}


double * readBalanceFile(string filename, int * elCount){
        
    double temp[MAX_ACCOUNT_NUM]; //temp array because number of elements is unknown
    
    ifstream balances(filename.c_str()); //open file
    
    if(!balances){ //if file was not open
        
        cout << "File can't be opened!" << endl;
        return NULL;
    }
    
    string curLine;
    for((*elCount) = 0; getline (balances, curLine); (*elCount)++) //iterate through each line
        temp[(*elCount)] = atof(curLine.substr(curLine.find_last_of(' ') + 1, curLine.length() - 1).c_str()); //extract number, convert from string to double and add to array
    
    
    double * storage = new double[(*elCount)]; //create exact size array
    
    for(int i = 0; i < (*elCount); i++){ //write data to new exact size array
         
        storage[i] = temp[i];
    }
    
    return storage;
}


double computeMean(double * data, int elCount){

    double mean = 0;
    
    for(int i = 0; i < elCount; i++) //get sum
        mean += data[i];
    
    return mean / elCount;
}


double computeMedian(double * data, int elCount){

    if(elCount % 2 == 0) //if even number of elements
        return (data[elCount / 2] + data[elCount / 2 - 1]) / 2;
    
    else //if odd
        return data[elCount / 2];
}


void printTable(double mean1, double median1, double mean2, double median2){
    
    
    cout << "-------------------------------------------------" << endl;
    cout << "|               " << "|               " << "|               |" << endl;
    cout << "|               " << "|     Mean      " << "|     Median    |" << endl;
    cout << "|               " << "|               " << "|               |" << endl;
    cout << "|-----------------------------------------------|" << endl;
    cout << "|               " << "|               " << "|               |" << endl;
    cout << "|Balances-1.txt " << "|   $" << left << setw(11) << fixed << setprecision(3) << mean1 << "|   $" << setw(11) << median1 << "|" << endl;
    cout << "|               " << "|               " << "|               |" << endl;
    cout << "|-----------------------------------------------|" << endl;
    cout << "|               " << "|               " << "|               |" << endl;
    cout << "|Balances-2.txt " << "|   $" << left << setw(11) << fixed << setprecision(3) << mean2 << "|   $" << setw(11) << median2 << "|" << endl;    cout << "|               " << "|               " << "|               |" << endl;
    cout << "-------------------------------------------------" << endl;
}
