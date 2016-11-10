/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include "helpers.h"


/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    
    // reuturn "false" in case "n" is negative number
    if(n < 0){
        return false;
    };
    
    //searching for "value" in "values" array
    for(int i = 0;i <= n;i++){
        //return "true" if it was found
        if(values[i] == value){
            return true;
            printf("%i", values[i]); 
        } 
        
    }
    //return "false" if there isn't "value" in "values" array
    return false;
}

search(2, [2,3,4,54],4);

