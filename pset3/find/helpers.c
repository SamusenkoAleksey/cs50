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
bool search(int key, int array[], int min, int max);
//bool binarySearch(int key, int array[], int min, int max);
void sort(int values[], int n);

/**
 * Returns true if value is in values of n values, else false.
 */
 
        // **LINEAR SEARCH**

// bool search(int value, int values[], int n)
// {
//     // TODO: implement a searching algorithm
    
//     // return "false" in case "n" is negative number
//     if(n < 0){
//         return false;
//     };
    
//     //searching for "value" in "values" values
//     for(int i = 0; i <= n ;i++){
//         //return "true" if it was found
//         if(values[i] == value){
//             return true;
//         } 
        
//     }
//     //return "false" if there isn't "value" in "values" values

//     return false;
//     return -1;

// }



/**
 * Sorts values of n values.
 */
 
        // **BINARY SEARCH**
        
// bool search(int value, int values[], int n){
    
//     if(binarySearch(value, values, 0, n)){
//         return true;
//     }
//     return false;
    
// }

// bool binarySearch(int key, int array[], int min, int max){
    
//     int midPoint;
    
//     if(max < min){
//         return  -1;
//     }else{
//         midPoint = findMidPoint(min, max); 
//     }
    
//     int currentValue = array[midPoint];
    
//     if(currentValue < key){
//       return binarySearch(key, array, midPoint + 1, max);
//     }else if(currentValue > key){
//       return binarySearch(key, array, min, midPoint - 1);
//     }else{
//         return true;
//     };
    
//     return 0;
//     return false;

// }


bool search(int key, int array[], int min, int max){
    if(min <= max){
        
        int middlePoint = (min + max)/2;
        
       
        if(key < array[middlePoint]){
            return search(key, array, min, middlePoint -1);
        }else if(key > array[middlePoint]){
            return search(key, array, middlePoint + 1, max);
        }else{
            //printf("work!");
            return true;
        };
        // printf("doesn\'t work!");
        // return false;
    }
   // printf("doesn\'t work!");
    return false;
    
}

int findMidPoint(int min, int max){
    int result = (min + max) / 2;
    return result;
}

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
