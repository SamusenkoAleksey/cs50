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


    // **LINEAR SEARCH**
    // return "false" in case "n" is negative number
    if(n < 0){
        return false;
    };
    
    //searching for "value" in "values" array
    for(int i = 0; i <= n ;i++){
        //return "true" if it was found
        if(values[i] == value){
            return true;
        } 
        
    }
    //return "false" if there isn't "value" in "values" array

    return false;
    return -1;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    
    //selection sort
    for(int i = 0; i < n - 1 ; i++){
        int current_minimum = values[i];
        int replaced_element;
        for(int j = i + 1; j < n ; j++){
            replaced_element = j;
           if(values[j] < current_minimum){
               current_minimum = values[j];
           }
        };
        if(current_minimum != values[i]){
            values[replaced_element] = values[i];
            values[i] = current_minimum;
        };
    };
    return;
}