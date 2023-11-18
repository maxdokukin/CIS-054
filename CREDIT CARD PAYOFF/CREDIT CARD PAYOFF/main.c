//
//  main.c
//  CREDIT CARD PAYOFF
//
//  Created by Max Dokukin on 24/02/2021.
//

#include <stdio.h>

#define YEARLY_INTEREST_RATE 22.24 / 100.0    /* 22.24%  = 0.2224 */
#define MONTHLY_INTEREST_RATE YEARLY_INTEREST_RATE/12
#define CREDIT_LIMIT  500.00    /* credit limit */
#define MAX_MONTHS  12          /* maximum months to display */

int main()
{
    /* Input values */
    double balance = 240.75;
    double payment = 35.00;
    double charges = 60.00;

    /* Computed values */
    double interest;
    double newBalance;
    int month = 1;

    /* table column headings */
    printf("%5s  %7s  %8s  %7s  %7s  %11s\n",
        "Month", "Balance", "Interest", "Payment", "Charges", "New Balance");

    do {
        interest = balance * MONTHLY_INTEREST_RATE;    // based on 12 months in a year
        newBalance = balance + interest + charges - payment;
        
        if(newBalance < 0){ //payment exceeds balance to pay
            
            payment = balance + interest;
            newBalance = 0;
        }
        
        // display table values
        printf("%5d  %7.2f  %8.2f  %7.2f  %7.2f  %11.2f\n",
            month, balance, interest, payment, charges, newBalance);

        month++;                /* update month number */
        balance = newBalance;   /* transfer newBalance to balance for next computation */
        
    } while (balance > 0.00 && balance < CREDIT_LIMIT && month != 13);
    
    if(balance == 0)
        printf("Balance was paid off!\n\n");
    
    else if(balance > CREDIT_LIMIT)
        printf("Credit limit was exceeded!\n\n");
    
    else
        printf("Balance was not paid off!\n\n");
}
