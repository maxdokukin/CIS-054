//
//  main.c
//  SENTENCE FORMATTING
//
//  Created by Max Dokukin on 25/02/2021.
//

#define MAX_SENT_LEN 256

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char sentence[MAX_SENT_LEN];
    
    printf ("Enter sentence: ");
    scanf  ("%[^\n]s", sentence);
    
    
    //DOT CHECK//
    int p = 0;
    for(p = 0; sentence[p] != '.' && p < MAX_SENT_LEN; p++);
        
    if(p == MAX_SENT_LEN){
        
        printf("Invalid sentence. Check for dot.\n\n");
        return 0;
    }
    
    
    //REMOVING WHITESPACES//
    for(int i = 0; sentence[i] != '\0'; i++){
        
        if(sentence[i] == '\t' || sentence[i] == '\n')
           sentence[i] = ' ';
    }
    
    
    //REMOVING EXTRA SPACES//
    for(int i = 0; sentence[i] != '\0'; i++)
        while(sentence[i] == ' ' && i + 1 < MAX_SENT_LEN && sentence[i + 1] == ' ')
            for(int j = i; sentence[j] != '\0'; j++)
                sentence[j] = sentence [j + 1];
      
    
    //MAKING ALL LOWER CASE//
    for(int i = 0; sentence[i] != '\0'; i++)
        if(sentence[i] >= 65 && sentence[i] <= 90)
            sentence[i] += 32;
    
    //MAKING FISRT CAPITAL//
    sentence[0] -= 32;
    
    
    printf("Formatted sentence : %s\n\n", sentence);
}


