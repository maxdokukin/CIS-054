//
//  main.c
//  LONG DISTANCE CALL
//
//  Created by Max on 01/03/2021.
//

#include <stdio.h>


//PARAMETERS//
#define DAY_RATE 0.40
#define EVENING_RATE 0.25
#define WEEKEND_RATE 0.15


//CONVERTING FUNCTIONS//
int stringToIntTime(char *time);
int stringToIntWeekDay(char *day);

//BILL COUNTING FUNCTIONS//
double getBill(int day, int startTime, int callLen);
double getRate(int day, int startTime);

//STRING FUNCTIONS//
int strLen(char *string);
int stringsEqual(char *str1, char *str2);
char *toUpperString(char *str);
int stringContains(char *sourceStr, char *testStr);


char *weekDays[] = {"MO", "TU", "WE", "TH", "FR", "SA", "SU"};



int main(int argc, const char * argv[]) {
    
    char day[2];
    char time[8];
    int callLength = 0;
    char exitFlag;
    
    double callCost = 0;
    
    printf("--------------------\nWelcome to bill counter 1.0\nDay input format: \"Mo\" or number of the day\nTime format: H:MM or HH:MM, Military or AM/PM\nPress |x| to exit\n--------------------\n");
    
    while(1){
        
        printf("--------------------\n");
        printf("Enter day of the week : ");
        scanf("%s", day);
        fflush(stdin);
        
        int dayNum = stringToIntWeekDay(toUpperString(day));
        
        if(dayNum < 0){
            
            printf("Wrong day input!\n\n");
            continue;
        }

        
        printf("Call start time : ");
        scanf("%s", time);
        fflush(stdin);
        
        int timeVal = stringToIntTime(time);
        
        if(timeVal < 0){
            
            printf("Wrong time input!\n\n");
            continue;
        }
        
        
        printf("Enter call duration (minutes) : ");
        scanf("%d", &callLength);
        fflush(stdin);
                
        if(callLength < 0){
            
            printf("Wrong call duration value!\n\n");
            continue;
        }

        
        callCost = getBill(dayNum, timeVal, callLength);
        
        
        printf("Call cost if $%.2lf\n", callCost);
        printf("--------------------\n");
        
        printf("Press any key to contiue ");
        scanf("%c", &exitFlag);
        fflush(stdin);
        
        if(exitFlag == 'X' || exitFlag == 'x')
            break;
    }
}


int stringToIntWeekDay(char *day){
    
    int weekDay = 0;
    
    if(day[0] >= '0' && day[0] <= '7')
        return day[0] - 48;
        
    while(weekDay < 7 && !stringsEqual(weekDays[weekDay++], day));
    
    return stringsEqual(weekDays[--weekDay], day)  ? ++weekDay : -1;
}


int stringToIntTime(char *time){
    
    if(!stringContains(time, ":"))
        return -1;
    
    
    int timeVal = 0;
    
    if(time[1] == ':') //time format n:nn
        timeVal += (time[0] - 48) * 100 + (time[2] - 48) * 10 + (time[3] - 48);
    
    else if(time[2] == ':')// time formar nn:nn
        timeVal += (time[0] - 48) * 1000 + (time[1] - 48) * 100 + (time[3] - 48) * 10 + (time[4] - 48);
    
    
    if(stringContains(toUpperString(time), "AM")){
        
        if(!(timeVal >= 100 && timeVal <= 1259))
            return -1;
        
        if(timeVal > 1159 )
            timeVal -= 1200;
    }
    
    if(stringContains(toUpperString(time), "PM")){
                
        if(!(timeVal >= 100 && timeVal <= 1259))
            return -1;
        
        if(timeVal < 1159 )
            timeVal += 1200;
    }
    
    return timeVal;
}


double getBill(int day, int startTime, int callLen){
    
    return callLen * getRate(day, startTime);
}


double getRate(int day, int startTime){
    
    double rate = 0;
    
    if(day > 5)
        rate = WEEKEND_RATE;
    
    else{
        if(startTime >= 800 && startTime <= 1800)
            rate = DAY_RATE;
        
        else
            rate = EVENING_RATE;
    }
    
    return rate;
}


//STRING FUNCTIONS//
int stringsEqual(char *str1, char *str2){
    
    if(strLen(str1) != strLen(str2))
        return 0;
    
    int totalLen = strLen(str1);
    
    int equalUntil;
    for(equalUntil = 0; str1[equalUntil] == str2[equalUntil] && str1[equalUntil] != '\0'; equalUntil++);
    
    return totalLen == equalUntil;
}


int strLen(char *string){
    
    int i = 0;
    while(string[i++] != '\0');
    return --i;
}


char *toUpperString(char *str){
    
    for(int i = 0; str[i] != '\0'; i++)
        if(str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
    
    return str;
}


int stringContains(char *sourceStr, char *testStr){
    
    int matchLen = strLen(testStr); //requred char sequence match length
    int matchCount = 0; //how many chars matched
    int matchNum = 0; //number of matches
    
    for(int i = 0; sourceStr[i] != '\0'; i++){
        
        if(sourceStr[i] == testStr[0]){
            
            while(sourceStr[i] != '\0' && sourceStr[i++] == testStr[matchCount])
                matchCount++;
            
            if(matchLen == matchCount)
                matchNum++;
            
            matchCount = 0;
            
            if(sourceStr[i] == '\0')
                break;
        }
    }
    
    return matchNum;
}
