//
//  main.c
//  FALAFEL LAB
//
//  Created by Max Dokukin on 14/03/2021.
//

#include <stdio.h>
#include <ctype.h>
#include <time.h>


#define TAX_RATE 8.7

#define FALAFEL_PRICE 5.15
#define SODA_PRICE 2.24
#define EXTRA_PRICE 1.57


void printMenu(void);
void getOrder(int *falafelCount, int *sodaCount, int *extraCount);
void printReceipt(int falafelCount, int sodaCount, int extraCount);

char inputChar(void);
void printTimeStamp(void);
void printBorderLine(){ printf("--------------------------------------------\n"); }
void printSplitLine(){ printf("|------------------------------------------|\n"); }


int main(int argc, const char * argv[]) {
    
    int falafelCount = 0, sodaCount = 0, extraCount = 0;
    
    printMenu();
    
    getOrder(&falafelCount, &sodaCount, &extraCount);
        
    printReceipt(falafelCount, sodaCount, extraCount);

    return 0;
}


void printMenu(void){
    
    printBorderLine();
    printf("|%33s         |\n", "Welcome to Falafel OS 1.0");
    printSplitLine();
    
    printf("|%24s%19s\n", "Menu", "|");
    printf("|%-20s                 $%2.2lf|\n", "Falafel", FALAFEL_PRICE);
    printf("|%-20s                 $%2.2lf|\n", "Soda", SODA_PRICE);
    printf("|%-20s                 $%2.2lf|\n", "Extra", EXTRA_PRICE);
    
    printBorderLine();

    printf("Selection:\nF for Falafel\nS for Soda\nX for Extra\nT to get total\n");
    printBorderLine();
}


void getOrder(int *falafelCount, int *sodaCount, int *extraCount){
    
    char selection = 0;
    
    while(selection != 'T'){
        
        printf("Make your selection (FSXT) : ");
    
        selection = inputChar();
        
        switch (selection){
                
            case 'F':
                (*falafelCount)++;
                break;
                
            case 'S':
                (*sodaCount)++;
                break;
                
            case 'X':
                (*extraCount)++;
                break;
                
            case 'T':
                break;
                
            default:
                printf("Wrong input!\n");
                break;
        }
    }
}


void printReceipt(int falafelCount, int sodaCount, int extraCount){
        
    double subtotal = falafelCount * FALAFEL_PRICE + sodaCount * SODA_PRICE + extraCount * EXTRA_PRICE;

    if(!subtotal){
        
        printf("There are no any items!\n\n");
        return;
    }
    
    printBorderLine();
    
    printTimeStamp();
    
    printSplitLine();
    
    //items info
    if(falafelCount){
            
        printf("|%-10s %2d", "Falafel", falafelCount);
        printf("   %1s  %3s%3.2lf    %1s    $%6.2lf|\n", "*", "$", FALAFEL_PRICE, "=", falafelCount * FALAFEL_PRICE);
    }
    
    if(sodaCount){
            
        printf("|%-10s %2d", "Soda", sodaCount);
        printf("   %1s  %3s%3.2lf    %1s    $%6.2lf|\n", "*", "$", SODA_PRICE, "=", sodaCount * SODA_PRICE);
    }

    if(extraCount){
            
        printf("|%-10s %2d", "Extras", extraCount);
        printf("   %1s  %3s%3.2lf    %1s    $%6.2lf|\n", "*", "$", EXTRA_PRICE, "=", extraCount * EXTRA_PRICE);
    }
    
    printSplitLine();
    
    //Subtotal tax and total info
    printf("|   %-10s  %21s%6.2lf|\n", "Subtotal", "$", subtotal);
    
    double tax = subtotal * TAX_RATE / 100;
    printf("|   %-10s  %21s%6.2lf|\n", "Tax", "$", tax);
    
    double total = subtotal + tax;
    printf("|   %-10s  %21s%6.2lf|\n", "Total", "$", total);

    printBorderLine();
}


void printTimeStamp(){
    
    time_t t = time(NULL);
    struct tm timeObj = *localtime(&t);
    
    printf("|%02d/%02d/%04d %25d:%02d:%02d|\n", timeObj.tm_mon + 1, timeObj.tm_mday, timeObj.tm_year + 1900, timeObj.tm_hour, timeObj.tm_min, timeObj.tm_sec);
}


char inputChar(){
    
    char inputVal = 0;
    
    int scanfCount = scanf("%c", &inputVal);
    fflush(stdin);
    
    if(scanfCount != 1){
        
        printf("Illegal entry\n");
        return -1;
    }
    
    inputVal = toupper(inputVal);

    return inputVal;
}
