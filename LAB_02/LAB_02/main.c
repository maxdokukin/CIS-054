//
//  main.c
//  LAB_02
//
//  Created by Max Dokukin on 08/02/2021.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    
    int teamSize;
    int playersOnTeam;
    int morePlayersNeeded;
    int extraPlayers;
    int scanfCount;
    
    printf("How many players should be on the team? ");
    scanfCount = scanf("%d", &teamSize);
    
    if(scanfCount != 1){
        
        printf("Illegal entry for team size\n");
        return 1;
    }
    if(teamSize < 1){
        
        printf("Negative values are not allowed\n");
        return 1;
    }
    
    printf("How many players are on the team? ");
    scanfCount = scanf("%d", &playersOnTeam);
    
    if(scanfCount != 1){
        
        printf("Illegal entry for players on the team\n");
        return 1;
    }
    if(playersOnTeam < 1){
        
        printf("Negative values are not allowed\n");
        return 1;
    }
    if(playersOnTeam < teamSize){
        
        printf("There are not enough players\n");
        morePlayersNeeded = teamSize - playersOnTeam;
        printf("%d player(s) are needed\n", morePlayersNeeded);
    }
    else if(playersOnTeam > teamSize){
        
        printf("There are too many players\n");
        extraPlayers = playersOnTeam - teamSize;
        printf("%d player(s) need to be eliminated\n", extraPlayers);
    }
    else
        printf("You have the correct number of players\n\n");
    
    
    return 0;
    
}
