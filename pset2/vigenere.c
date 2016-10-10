#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int IsupperIslower(char elem);

int main (int argc, char* argv[]){
    
    //check if the key work was entered
    if(argc != 2){
        printf("You must enter the key word!\n");
        return 1;
    };
    
    string key_word = (argv[1]);
    
    //testing if the key word contains only alphabetical characters
    for(int i = 0, n = strlen(key_word) ; i < n ; i++){
        if(!isalpha(key_word[i])){
            printf("The key word has to contain only alphabetical characters!\n");
            return 1;
        }
    };
    
    //plaintext
    string plain_text = GetString();
    
    for (int i = 0, n = strlen(plain_text); i < n; i++ ){
        
        char letter_text = plain_text[i];
        
        if(isalpha(letter_text)){
            //starting the plain text process
            int up_low_letter_text = IsupperIslower(letter_text);
            
            //here we are getting ascii code of the letter
            int ascii_letter_text = letter_text;
                //getting alphabetical value from the ascii one
            int alphabetical_letter_index_text = (ascii_letter_text - up_low_letter_text);
            
            
            
            //working with the key word here--------------
            
            int word_length = strlen(key_word);
            char letter_word = key_word[ i % word_length];
            int up_low_letter_word = IsupperIslower(letter_word);
            int ascii_letter_word = letter_word;
            int alphabetical_letter_index_word = (ascii_letter_word - up_low_letter_word);
            //--------------------------------------------
            
            int alphabetical_result = (alphabetical_letter_index_text + alphabetical_letter_index_word) % 26;
            int ascii_result = (alphabetical_result + up_low_letter_text);
            printf("%c", ascii_result);
        }else{
            printf("%c", letter_text);
        };
        
    };
    
    printf("\n");
   
}




int IsupperIslower(char elem){
    
    if(isupper(elem)){
        return 65;
    }else{
        return 97;
    }
}