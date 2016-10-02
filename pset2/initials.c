#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void){
    
    //asking user for his/her name
    string name = GetString();
    
    //checking if the tring exist
    if(name != NULL){
        //creating capitalized letters
      for(int i = 0, str_length = strlen(name); i <= str_length; i++){
        if(i == 0){
            printf("%c", toupper(name[i]));
        }else if(name[i] == (char)32){
            printf("%c", toupper(name[i+1]));
        }
      }
      printf("\n");
      // the letters are created and printed now
    }
    
}