//
//  main.c
//  LAB_05
//
//  Created by Max Dokukin on 15/02/2021.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char player1Hand;
    char player2Hand;
        
    while(1){
            
        //PLAYER 1 INPUT//
        
        printf("Player 1, choose your hand : ");

        int scanfCount = scanf("%c", &player1Hand);
        fflush(stdin);
        
        if(scanfCount != 1){
            
            printf("Illegal entry\n\n");
            continue;
        }
        
        if(player1Hand > 90)
            player1Hand -= 32;
        
        
        if(!(player1Hand == 'R' || player1Hand == 'P' || player1Hand == 'S' || player1Hand == 'X')){
            
            printf("Wrong value\n\n");
            continue;
        }
                
        //PLAYER 2 INPUT//
        printf("Player 2, choose your hand : ");

        scanfCount = scanf("%c", &player2Hand);
        fflush(stdin);

        if(scanfCount != 1){
            
            printf("Illegal entry\n");
            continue;
        }
        
        if(player2Hand > 90)
            player2Hand -= 32;
        
        if(!(player2Hand == 80 ||player2Hand == 82 || player2Hand == 83 || player2Hand == 88)){
            
            printf("Wrong value\n");
            continue;
        }
    
        
        //PROCESSING//
    
        if(player1Hand == 88 || player2Hand == 88){ //stop game
            
            printf("Game over!\n\n");
            break;
        }
        
        if(player1Hand == player2Hand){
            
            printf("Draw!\n\n");
            continue;
        }
        
        int winner = 0;
        
        if(player1Hand == 'R'){
            
            if(player2Hand == 'P')
                winner = 2;
            
            else if(player2Hand == 'S')
                winner = 1;
        }
        
        else if(player1Hand == 'P'){
            
            if(player2Hand == 'R')
                winner = 1;
            
            else if(player2Hand == 'S')
                winner = 2;
        }
        
        else if(player1Hand == 'S'){
            
            if(player2Hand == 'R')
                winner = 2;
            
            else if(player2Hand == 'P')
                winner = 1;
        }
        
        
        //OUTPUT//
        
        if(winner == 1)
            printf("Player 1 won!\n\n");
        else if(winner == 2)
            printf("Player 2 won!\n\n");
    }
}
