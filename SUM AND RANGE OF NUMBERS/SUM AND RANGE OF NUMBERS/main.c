//
//  main.c
//  SUM AND RANGE OF NUMBERS
//
//  Created by Max Dokukin on 20/02/2021.
//

#include <stdio.h>
#define NUM_COUNT 10

int main(int argc, const char * argv[]) {
   
    int numCount = 0;
    
    int oddSum = 0, evenSum = 0, allSum = 0, minVal = 0, maxVal = 0;
    
    while(numCount < NUM_COUNT){
        
        int currentNum;
        printf("Enter number : ");

        int scanfCount = scanf("%d", &currentNum);
        
        if(scanfCount != 1){
            
            printf("Illegal entry\n\n");
            fflush(stdin);
            continue;
        }
        
        if(currentNum < 0){
            
            printf("Negative values are not allowed!\n\n");
            continue;
        }
        
        
        if(currentNum % 2 == 0)
            evenSum += currentNum;

        else
            oddSum += currentNum;
        
        
        allSum += currentNum;
        
        
        if(numCount == 0){
            
            minVal = currentNum;
            maxVal = currentNum;
        }
        else if(currentNum > maxVal){
            
            maxVal = currentNum;
        }
        else if(currentNum < minVal){
            
            minVal = currentNum;
        }
        
        
        numCount++;
    }
    
    double average = allSum / (double) NUM_COUNT;
    
    
    printf("Odd number sum : %d\n", oddSum);
    printf("Even number sum : %d\n", evenSum);
    printf("All number sum : %d\n", allSum);
    printf("Lowest value : %d\n", minVal);
    printf("Highest value : %d\n", maxVal);
    printf("Average : %.2lf\n\n", average);
}
