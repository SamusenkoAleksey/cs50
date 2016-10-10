#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char* argv[]){
    
    //check the arguments
    if(argc != 2){
        printf("You must eenter the key of kode. Any positive number!\n");
        return 1;
    };
    
    //setting the key value
    int key = atoi(argv[1]);
    
    //asking the user to enter plaintext
    string plain_text = GetString();
    
    for (int i = 0, n = strlen(plain_text); i < n; i++ ){

        char letter = plain_text[i];
        
        //checking if the char is an alphabetic letter
        if(isalpha(letter)){
            //if the char is a capital letter or not
            int isupper_islower = 0; 
            
            if(isupper(letter)){
                isupper_islower = 65;
            }else{
                isupper_islower = 97;
            };
            //here we are getting ascii code of the letter
            int ascii_capital_letter = letter;
                //getting alphabetical value from the ascii one
            int alphabetical_letter_index = (ascii_capital_letter - isupper_islower);
                //this is a formula to around the alpahbet
            int alphabetical_result = (alphabetical_letter_index + key) % 26;
                //getting ascii value from the alphabeticalone
            int ascii_result = (alphabetical_result + isupper_islower);
                
            printf("%c", ascii_result);    
            
        }else{
            printf("%c", plain_text[i]);    
        };
        
    };
    printf("\n");
    return 0;
}