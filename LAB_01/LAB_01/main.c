//  main.c
//  Paycheck_Lab_01
//  Created by Maxim Dokukin on 01/02/2021.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int hourNum = 0, payRate = 0;
    
    printf("Enter hours number: ");
    scanf (" %i", &hourNum);
    
    printf("Enter pay rate: ");
    scanf (" %i", &payRate);
    
    int regHours = 0, overHours = 0;
    
    if(hourNum <= 40)
        regHours = hourNum;
    
    else if(hourNum > 40){
        
        regHours = 40;
        overHours = hourNum % 40;
    }

    int regPay = regHours * payRate;
    float overPay = overHours * payRate * 1.5;
    float totalPay = regPay + overPay;
    
    printf("Regular hours check : %i$\nOver hours check : %.2f$\nTotal check : %.2f$\n", regPay, overPay, totalPay);
    
    return 0;
}
