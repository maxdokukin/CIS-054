//
//  main.c
//  ENGLISH AND METRIC CONVERSION
//
//  Created by Max Dokukin on 12/03/2021.
//

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX_INPUT_LEN 64

//BASIC FUNCTIONS//
char menuSelect(void);
double inputDouble(void);


//FUNCTIONS FOR ADVANCED MODE//
void freeMode(void);
int decodeInput(char *originSystem, double *value);
double extractValue(char *input);
int isEmpericalValue(char *input);
int isMetricValue(char *input);


//STRING FUNCTIONS//
int strLen(char *string);
int stringsEqual(char *str1, char *str2);
char *toUpperString(char *str);
int stringContains(char *sourceStr, char *testStr);
double stringToDouble(char *string);


int main(int argc, const char * argv[]) {
                
    int goOnFlag = 1;
    double value = 0;
    
    while(goOnFlag){
        
        
        
        switch (menuSelect()){
                
            case 'E':
                printf("-----\nInches : ");
                
                value = inputDouble();
                if(value < 0)
                    continue;
                
                printf("Centimetres : %.2lf\n", value * 2.54);
            break;
                
                
            case 'M':
                printf("-----\nCentimetres : ");
                
                value = inputDouble();
                if(value < 0)
                    continue;
                
                printf("Inches : %.2lf\n", value / 2.54);
            break;
            
                
            case 'Q':
                goOnFlag = 0;
            break;
                
                
            case 'F':
                freeMode();
            break;
        }
        
    }
}



//BASIC FUNCTIONS//
char menuSelect(){
    
    char selection = 0;
    
    while(selection != 'E' && selection != 'M' && selection != 'Q' && selection != 'F'){
        
        if(selection != 0)
            printf("-----\nIllegal entry! Try again!\n");
        
        printf("-----\nEnter E to convert from English to Metric\nEnter M to convert from Metric to English\nEnter Q for exit\nEnter F to try free mode!\n-----\n");
        
        scanf("%c", &selection);
        fflush(stdin);
        selection = toupper(selection);
    }
    
    return selection;
}


double inputDouble(){
    
    double inputVal = 0;
    
    int scanfCount = scanf("%lf", &inputVal);
    fflush(stdin);
    
    if(scanfCount != 1){
        
        printf("Illegal entry\n");
        return -1;
    }
    
    if(inputVal < 0){
        
        printf("Negative values are not allowed!\n");
        return -1;
    }
    
    return inputVal;
}
//HERE ENDS CODE THAT IS NECESSARY TO COMPLETE ASSIGNMENT//



//ADVANCED FUNCTIONS//
void freeMode(){
    
    printf("-----\nWelcome to free mode!\nEnter value and specify it by adding\n(in, inch, inches)\nor\n(cm, centimetre, centimetres)\n-----\n");
    
    double value = 0;
    char originSystem = 0;
    int goOnFlag = 1;
    
    while(goOnFlag){
        
        printf("Value 1 : ");
        
        if(decodeInput(&originSystem, &value)){
            
            switch (originSystem){
                    
                case 'M':
                    printf("Value 2 : %.2f inches\n", value / 2.54);
                break;
                    
                    
                case 'E':
                    printf("Value 2 : %.2f centimetres\n", value * 2.54);
                break;
                
                    
                case 'Q':
                    goOnFlag = 0;
                break;
            }
            
            printf("-----\n");
        }
        else
            printf("Wrong input!\n");
    }
}


int decodeInput(char *originSystem, double *value){
    
    char input[MAX_INPUT_LEN];
    
    scanf("%[^\n]s", input);
    fflush(stdin);
    
    if(isMetricValue(input)){
        
        *originSystem = 'M';
        *value = extractValue(input);
    }
    else if(isEmpericalValue(input)){
        
        *originSystem = 'E';
        *value = extractValue(input);
    }
    else if(stringContains(input, "q") == 1 ||stringContains(input, "Q") == 1){
        
        *originSystem = 'Q';
    }
    else{
        
        printf("Invalid specifier!\n");
        return 0;
    }
    
    return 1;
}


double extractValue(char *input){
        
    char digits[16];
    
    //find first number's char
    int pointer;
    for(pointer = 0; (input[pointer] < '0' || input[pointer] > '9') && input[pointer] != '\0'; pointer++);
    
    //rewrite all number's chars to new array
    int numberLength;
    for(numberLength = 0; (input[pointer] >= '0' && input[pointer] <= '9') || input[pointer] == '.'; pointer++, numberLength++)
        digits[numberLength] = input[pointer];
    
    digits[numberLength] = '\0';
        
    return stringToDouble(digits);
}


int isEmpericalValue(char *input){
    
    if(stringContains(input, "in"))
        return 1;

    return 0;
}


int isMetricValue(char *input){
    
    if(stringContains(input, "cm"))
        return 1;
    
    else if(stringContains(input, "cent"))
        return 1;

    return 0;
}



//STRING FUNCTIONS//
double stringToDouble(char *string){
    
    int numberLen = strLen(string);
    
    double outputNumber = 0;
    
    if(stringContains(string, ".")){ //there is dot
        
        int digitsAfterDot = 0;
        int currentPower = numberLen  - 2; //because there is a dot and zero power
        
        for(int i = 0; i < numberLen; i++){
            
            if(digitsAfterDot) //dot was detected, count digits after it
                digitsAfterDot++;
            
            
            if(string[i] == '.'){ //dot detected, start counter
                digitsAfterDot++;
                continue;
            }
            
            outputNumber += (string[i] - 48) * pow(10, currentPower--);
        }
        
        outputNumber /= pow(10, --digitsAfterDot);
    }
    
    else{ //no dot
        
        for(int i = 0; i < numberLen; i++)
            outputNumber += (string[i] - 48) * pow(10, numberLen - i - 1);
    }
        
    return outputNumber;
}


int stringsEqual(char *str1, char *str2){
    
    if(strLen(str1) != strLen(str2))
        return 0;
    
    int totalLen = strLen(str1);
    
    int equalUntil;
    for(equalUntil = 0; str1[equalUntil] == str2[equalUntil] && str1[equalUntil] != '\0'; equalUntil++);
    
    return totalLen == equalUntil;
}


int strLen(char *string){
    
    int i = 0;
    while(string[i++] != '\0');
    return --i;
}


char *toUpperString(char *str){
    
    for(int i = 0; str[i] != '\0'; i++)
        if(str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
    
    return str;
}


int stringContains(char *sourceStr, char *testStr){
    
    int matchLen = strLen(testStr); //requred char sequence match length
    int matchCount = 0; //how many chars matched
    int matchNum = 0; //number of matches
    
    for(int i = 0; sourceStr[i] != '\0'; i++){
        
        if(sourceStr[i] == testStr[0]){
            
            while(sourceStr[i] != '\0' && sourceStr[i++] == testStr[matchCount])
                matchCount++;
            
            if(matchLen == matchCount)
                matchNum++;
            
            matchCount = 0;
            
            if(sourceStr[i] == '\0')
                break;
        }
    }
    
    return matchNum;
}
