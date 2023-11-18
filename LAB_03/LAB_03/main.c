//
//  main.c
//  LAB_03
//
//  Created by Max Dokukin on 02/07/2021.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int quarters;
    int dimes;
    int nickels;
    int pennies;
    
    float total;
    
    int scanfCount;
    
    printf("***Welcome to Max's accounting software***\n\n");
    
    printf("Enter number of quaters : ");
    scanfCount = scanf("%d", &quarters);
    
    if(scanfCount != 1){
        
        printf("Illegal entry\n");
        return 1;
    }
    if(quarters < 0){
        
        printf("Negative values are not allowed\n");
        return 1;
    }
    
    
    printf("Enter number of dimes : ");
    scanfCount = scanf("%d", &dimes);
    
    if(scanfCount != 1){
        
        printf("Illegal entry\n");
        return 1;
    }
    if(dimes < 0){
        
        printf("Negative values are not allowed\n");
        return 1;
    }
    
    
    printf("Enter number of nickels : ");
    scanfCount = scanf("%d", &nickels);
    
    if(scanfCount != 1){
        
        printf("Illegal entry\n");
        return 1;
    }
    if(nickels < 0){
        
        printf("Negative values are not allowed\n");
        return 1;
    }
    
    
    printf("Enter number of pennies : ");
    scanfCount = scanf("%d", &pennies);
    
    if(scanfCount != 1){
        
        printf("Illegal entry\n");
        return 1;
    }
    if(pennies < 0){
        
        printf("Negative values are not allowed\n");
        return 1;
    }
    
    total = quarters * 0.25 + dimes * 0.1 + nickels * 0.05 + pennies * 0.01;
    
    printf("\nTotal is : $%.2f\n\n", total);
    
    return 0;
}
