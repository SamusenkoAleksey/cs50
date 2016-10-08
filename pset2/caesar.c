#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char* argv[]){
    
    //check the arguments
    if(argc != 2){
        return 1;
    };
    
    //setting the key value
    int k = atoi(argv[1]);
    
    //asking the user to enter plaintext
    printf("plaintext:\n");
    string plain_text = GetString();
    
    for (int i = 0, n = strlen(plain_text); i < n; i++ ){

        char letter = plain_text[i];
        
        //checking if the char is an alphabetic letter
        if(isalpha(letter)){
            printf("%c\n", letter);
        };
        
        
        //checking if the letter is in the alphabet
        
    };
    
    printf("\n%d",k);
}