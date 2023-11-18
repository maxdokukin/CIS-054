//
//  main.cpp
//  BINARY SEARCH OF STRUCTURED RECORDS
//
//  Created by Max on 24/03/2021.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctype.h>
#include <string.h>


using namespace std;


// define the max number of records in the file
const int LIST_LENGTH = 256;

// define the lengths of each character array
const int NAME_SIZE = 40;
const int NUMBER_SIZE = 13;
const int LINE_SIZE = 80;

// define the structure for the array of records
typedef struct S_REC {
    char name[NAME_SIZE];
    char number[NUMBER_SIZE];
} PhoneRec;


PhoneRec* readPhoneFile(char *filename, int *listsize); // reads phone file and creates array of structure

char *inputString(string complementaryText, int maxStringLen); //inputs string from user
int isDigit(char testChar);
void stringUpper(char *str); //makes string upper case
void printSearchResult(char searchType, PhoneRec *record, int searchNum, char *searchRequest);


int sequentalSearch(PhoneRec *List, int listLen, char* searchString, int *searchNum);
int binarySearch(PhoneRec *List, int listLen, char* searchString, int *searchNum);



int main(int argc, char* argv[]) {
    
    cout << strcasecmp("lucky stores", "LUCKY STORES");
    
    char filepath[] = "/Users/xewe/Documents/CIS-054/BINARY SEARCH OF STRUCTURED RECORDS/BINARY SEARCH OF STRUCTURED RECORDS/phony422.txt";
    int listsize = 0;
    int foundID = -1;
    int searchNum = 0; //search iterations counter

    PhoneRec *List = readPhoneFile(filepath, &listsize); //read file

    char *searchRequest = inputString("Enter search request", LINE_SIZE); //input search request
    
    
    //sequental search
    foundID = sequentalSearch(List, listsize, searchRequest, &searchNum);
    
    if(foundID == -1){
        
        cout << "Not found" << endl;
        return -1;
    }
    
    printSearchResult('S', &List[foundID], searchNum, searchRequest);

    
    //binary search
    foundID = binarySearch(List, listsize, searchRequest, &searchNum);
    
    if(foundID == -1){
        
        cout << "Not found" << endl;
        return -1;
    }
    
    printSearchResult('B', &List[foundID], searchNum, searchRequest);
}


//prints search result
void printSearchResult(char searchType, PhoneRec *record, int searchNum, char *searchRequest){
    
    cout << "\n+------------------------------------------------+" << endl;
    
    if(searchType == 'S')
        cout << "|                SEQUENTAL SEARCH                |" << endl;
    
    else if(searchType == 'B')
        cout << "|                 BINARY SEARCH                  |" << endl;

    
    cout << "|------------------------------------------------|" << endl
         << "|" << left << setw(27) << "Name" << "|" << setw(20) << "Phone" << "|" << endl
         << "|---------------------------|--------------------|" << endl;

    cout << "|" << left << setw(27) << (*record).name << "|" << setw(20) << (*record).number <<  "|" << endl;

    
    cout << "|------------------------------------------------|" << endl
         << "|   Found in " << setw(4) << searchNum << " iterations"
         << right << setw(22) << "|" << endl
         << "+------------------------------------------------+" << endl;
}


//makes string to upper case
void stringUpper(char *str){
    
    for(int i = 0; str[i]; i++)
        str[i] = toupper(str[i]);
}


//sequental search by phone or name
int sequentalSearch(PhoneRec *List, int listLen, char* searchString, int *searchNum){
    
    (*searchNum) = 0;
    
    if(isDigit(searchString[0]))
        while((*searchNum) < listLen && strcmp(List[*searchNum].number, searchString))
            (*searchNum)++;
    
    else
        while((*searchNum) < listLen && strcasecmp(List[*searchNum].name, searchString) != 0)
            (*searchNum)++;
    
    return (*searchNum) == listLen ? -1 : (*searchNum);
}

//binary search by phone or name
int binarySearch(PhoneRec *List, int listLen, char* searchRequest, int *searchNum){
    
    (*searchNum) = 0;

    int lowerBound = 0;
    int upperBound = listLen - 1;
    int midPoint = 0;

    while (lowerBound <= upperBound){
                
        (*searchNum)++;

        midPoint = (lowerBound + upperBound) / 2;
        
        if(isDigit(searchRequest[0])){ //if searching by number
                
            if (strcmp(List[midPoint].number, searchRequest) < 0)
                lowerBound = midPoint + 1;
            
            else if (strcmp(List[midPoint].number, searchRequest) > 0)
                upperBound = midPoint - 1;
            
            else
                return midPoint;
        }
        else{ // if searching by name
            
            if (strcasecmp(List[midPoint].name, searchRequest) < 0)
                lowerBound = midPoint + 1;
            
            else if (strcasecmp(List[midPoint].name, searchRequest) > 0)
                upperBound = midPoint - 1;
            
            else
                return midPoint;
        }
    }
    
    return -1;
}


//inputs string
char *inputString(string complementaryText, int maxStringLen){
    
    char *output = new char[maxStringLen];

    cout << complementaryText << " : ";
    cin.getline(output, 80);

    return output;
}


//reads phone file andd writes data to array
PhoneRec* readPhoneFile(char* filename, int *listsize){
    
    ifstream PhoneFile(filename);

    if (!PhoneFile) {
        cerr << "Unable to open " << filename << endl;
        return NULL;
    }
    
    PhoneRec *List = new PhoneRec[LIST_LENGTH];

    char line[LINE_SIZE];
    char* ptr;

    
    line[0] = 0;
    PhoneFile.getline(line, LINE_SIZE);
    
    while (!PhoneFile.eof() && *listsize < LIST_LENGTH && line[0]) {
        if (strlen(line) > 1) {
                        
            ptr = strtok(line, ".");
            strcpy (List[*listsize].name, ptr);
          
            ptr = strtok(NULL, ".\r\n");
            strcpy (List[*listsize].number, ptr);

            (*listsize)++;
        }
        line[0] = 0;
        PhoneFile.getline(line, LINE_SIZE);
    }
    
    PhoneFile.close();

    return List;
}


int isDigit(char testChar){
    
    return testChar >= 48 && testChar <= 57;
}
