#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void){
    
    int counter = 0;
    float userAnswer;
    
    do{
        printf("O hai! How much change is owed?\n");
        userAnswer = GetFloat() * 100;
    }while(userAnswer <= 0);
    
    int roundedNumber = round(userAnswer);
    
    while(roundedNumber){
        if(roundedNumber == 25 || roundedNumber > 25){
            counter ++;
            roundedNumber -= 25;
        }else if(roundedNumber == 10 || roundedNumber > 10){
            counter ++;
            roundedNumber -= 10;
        }else if(roundedNumber == 5 || roundedNumber > 5){
            counter ++;
            roundedNumber -= 5;
        }else{
            counter ++;
            roundedNumber --;
        }
       
    }
     
    printf("%d\n", counter);
        
}