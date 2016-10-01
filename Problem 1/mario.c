#include <cs50.h>
#include <stdio.h>

int main(void){
    
    int height;
    //validation of the height
    do{
        printf("Please the height of the half-pyramind:\n");
        height = GetInt();
    }while(height < 0 || height >= 24);
    
    for(int i = 1; i <= height; i++){
        
        //drawing spaces
        for (int j = i; j <= (height-1); j++){
            printf(" ");
        }
        //drawing "briks" of half-pyramind
        for(int k = 1; k <= i; k ++){
            if(k == 1){
                printf("##");
            }else{
                printf("#");
            }
        }
        
        printf("\n");
    }
}