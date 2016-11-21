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
#include <math.h>
#include <stdio.h>

int findMidPoint(int min, int max);

/**
 * Returns true if value is in values of n values, else false.
 */
 
        // **LINEAR SEARCH**

bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    
    // return "false" in case "n" is negative number
    if(n < 0){
        return false;
    };
    
    //searching for "value" in "values" values
    for(int i = 0; i <= n ;i++){
        //return "true" if it was found
        if(values[i] == value){
            return true;
        } 
        
    }
    //return "false" if there isn't "value" in "values" values

    return false;
    return -1;

}



/**
 * Sorts values of n values.
 */
 
        // **BINARY SEARCH**
        
// bool search(int value, int values[], int n){
//     int min = 0;
//     int max = n;
//     int midpoint;
    
//     if (max < min){
//         return -1;
//     }else{
//         midpoint = findMidPoint(min, max);
//         printf("%c", midpoint);
//     };
    
//     for(int i = 0; i < n; i++){
//         if(values[midpoint] < value){
//             search(value, values, midpoint + 1);
//         }else if(values[midpoint] > value){
//             search(value, values, midpoint - 1);
//         }else if(values[midpoint] == value){
//             return true;
//         };
//     };

//     return false;
    
// };



void sort(int values[], int n)
{
    
    //selection sort
    for(int i = 0; i < n - 1 ; i++){
        int current_minimum = values[i];
        int replaced_index;
        for(int j = i + 1; j < n ; j++){
           if(values[j] < current_minimum){
               current_minimum = values[j];
               replaced_index = j;
           };
        };
        if(current_minimum != values[i]){
             values[replaced_index] = values[i];
             values[i] = current_minimum;
        };
    };
    
    return;
}

int findMidPoint(int min, int max){
    int result = (min + max) / 2;
    return result;
}

