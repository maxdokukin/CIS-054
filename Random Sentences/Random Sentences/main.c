//
//  main.c
//  Random Sentences
//
//  Created by Max Dokukin on 25/02/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_LEN 32
#define MAX_OUTPUT_LEN 256
#define OUTPUT_SENTENCE_NUM 20


char *getRandomWorld(char **array, int size);
void mergeStrings(char* stringA, char* stringB);
int isVowel(char a);


//VOCABULARY//
char * articles[] = {"the", "a", "one", "some", "any"};
char * adjectives[] = {"brave", "orange", "fast", "slow", "smart", "emotional", "unique"};
char * nouns[] = {"boy", "girl", "dog", "town", "car", "truck", "cat", "bird", "house"};
char * verbs[] = {"drove", "jumped", "ran", "walked", "skipped"};
char * prepositions[] = {"to", "from", "over", "under", "on"};


const char order[] = "aANVPaAN";
//defines the order of parts of speech//
/*
 a - article
 A - adjectie
 N - noun
 V - verb
 P - preposition
 */

const int articleCount = sizeof(articles)/sizeof(char*);
const int adjectiveCount = sizeof(adjectives)/sizeof(char*);
const int nounCount = sizeof(nouns)/sizeof(char*);
const int verbCount = sizeof(verbs)/sizeof(char*);
const int prepositionCount = sizeof(prepositions)/sizeof(char*);



int main(int argc, const char * argv[]) {
    
    srand((unsigned int) time(0));
    
    for(int i = 0; i < OUTPUT_SENTENCE_NUM; i++){
                
        char outputSentence[MAX_OUTPUT_LEN];
        outputSentence[0] = '\0';
        
        int articleAPlaced = 0;

        for(int currentWord = 0; order[currentWord] != '\0'; currentWord++){
            
            char *word = NULL;
            
            switch (order[currentWord]){
                
                case 'a':
                word = getRandomWorld(articles, articleCount);
                break;
                    
                case 'A':
                word = getRandomWorld(adjectives, adjectiveCount);
                break;
                    
                case 'N':
                word = getRandomWorld(nouns, nounCount);
                break;
                    
                case 'V':
                word = getRandomWorld(verbs, verbCount);
                break;
                    
                case 'P':
                word = getRandomWorld(prepositions, prepositionCount);
                break;
            }
            
            
            if(articleAPlaced){ //if previous word was article a
                
                if(isVowel(word[0])) //if current word starts from vowel
                    mergeStrings(outputSentence, "n"); //add n (a->an)

                articleAPlaced = 0; //reset flag
                mergeStrings(outputSentence, " "); //add space
            }
            
            
            mergeStrings(outputSentence, word); //add new world
            
            
            if(word[0] == 'a' && word[1] == '\0') //check if the current word is a article
                articleAPlaced = 1; //make a flag

            
            if(order[currentWord + 1] != '\0' && !articleAPlaced)
                mergeStrings(outputSentence, " "); //add space
        }
        
        outputSentence[0] -= 32; //make first letter capital
        mergeStrings(outputSentence, "."); //add dot
        
        printf("%d. %s\n", i + 1, outputSentence);
    }
    printf("\n");
}
        

char *getRandomWorld(char **array, int size){
    
    int index = rand() % size;
    
    return array[index];
}

void mergeStrings(char* stringA, char* stringB){
    
    int startIndex;
    for(startIndex = 0; stringA[startIndex] != '\0'; startIndex++);
    
    int finalIndex;
    for(finalIndex = 0; startIndex + finalIndex < MAX_OUTPUT_LEN && stringB[finalIndex] != '\0'; finalIndex++)
        stringA[startIndex + finalIndex] = stringB[finalIndex];
    
    stringA[startIndex + finalIndex] = '\0';
}

int isVowel(char a){
    
    return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}
