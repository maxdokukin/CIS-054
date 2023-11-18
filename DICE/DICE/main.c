//
//  main.c
//  DICE
//
//  Created by Max Dokukin on 15/03/2021.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ITERATION_NUM 100000


int randomRange(int lowerBound, int upperBound);
int rollDice(void);
void printGraph(int * array);


int main(int argc, const char * argv[]) {
        
    srand((unsigned int) time(NULL)); //initialize random
    
    int results[13]; //storage for results
    
    for(int i = 0; i < ITERATION_NUM; i++) //perform experiment
        results[rollDice()]++; //fastest way to record results
    
    for(int i = 2; i < 13; i++) //print results
        printf("%2d scores rolled %4d times\n", i, results[i]);
    
    printGraph(results); //plot a graph

    return 0;
}


int rollDice(){
    
    return randomRange(1, 6) + randomRange(1, 6);
}


int randomRange(int lowerBound, int upperBound){
    
    return rand() % (upperBound - lowerBound + 1) + lowerBound;
    
}
//THE END OF CODE THAT IS NECESSARY TO COMPLETE ASSIGNMENT//



#define GRAPH_HEIGHT 20

void printGraph(int * array){
    
    int maxValue = 0;
    for(int i = 2; i < 13; i++) //find maximum value
        if(array[i] > maxValue)
            maxValue = array[i];
    
    
    float bars[11]; //array with height of bars that repserent number of score rolled
    for(int i = 0; i < 11; i++)
        bars[i] = (float) GRAPH_HEIGHT * ((float) array[i + 2] / (float) maxValue); //calculate height of eaxh bar
        
    printf("---------------------------------------------------\n");
    
    float valueStep = maxValue / (float) GRAPH_HEIGHT;
    
    for(int i = GRAPH_HEIGHT; i > 0; i--){
        
        //printing single line of graph
        printf("|%5.0f", valueStep * i); //value of the line
        
        for(int j = 0; j < 11; j++){ //determine for each bar if there it is on a graph
            
            if(bars[j] >= i)
                printf("|###");
            else if(bars[j] + 0.5 >= i)
                printf("|___");
            else
                printf("|   ");
        }
        
        printf("|\n"); //next line
    }
    
    printf("|-------------------------------------------------|\n|     ");
    
    for(int i = 2; i <= 12; i++) //print bar names (from 2 to 12 scores rolled)
        printf("| %-2d", i);
    
    printf("|\n---------------------------------------------------\n");
}
