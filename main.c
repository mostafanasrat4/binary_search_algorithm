#include <stdio.h>
#include <stdlib.h>

#define SPACER printf("----------------------------------------------\n")


void insertion_sort(int* arr, int length);
int binary_search(int* arr, int length, int key);


int main(){
    SPACER;
    printf("                WELCOME             \n");
    SPACER;

    // Read the array elements from user and the key to search for 
    int array_length, key, index;
    printf("Enter the array size: ");
    scanf("%d", &array_length);
    int* array = (int*) malloc(array_length * sizeof(int));
    printf("\nEnter the %d integers of the array: \n", array_length);
    for(int i=0; i<array_length; i++){
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }
    SPACER;

    printf("Enter a key to search for: ");
    scanf("%d", &key);
    SPACER;

    // Print array before sorting
    printf("Unsorted array = {%d", array[0]);
    for(int i=1; i<array_length; i++){
        printf(", %d", array[i]);
    }
    printf("}\n");
    SPACER;
    
    index = binary_search(array, array_length, key);
    
    // Print array after sorting
    printf("Sorted array   = {%d", array[0]);
    for(int i=1; i<array_length; i++){
        printf(", %d", array[i]);
    }
    printf("}\n");
    SPACER;

    if(index == -1){
        printf("The key (%d) is not found in the array.\n", key);
    }
    else{
        printf("The key (%d) is found at index (%d) in the sorted array.\n", key, index);
    }
    SPACER;
}

// Sort a given array ascendingly, with time comlexity O(n^2)
void insertion_sort(int* arr, int length){
    for(int i = 1; i<length; i++){
        int key = arr[i];
        int j = i-1;
        while(key<arr[j] && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

/* Implements the binary search algorithm to search for the given "key"
There are three inputs:
1. "arr": The unsorted integers array
2. "length": The length of the array
3. "key": The integer to search for
The index of the key in the sorted array is returned,
If not found, "-1" will be returned
*/
int binary_search(int* arr, int length, int key){

    insertion_sort(arr, length); // sort the given unsorted array

    // Binary search algorithm
    int start=0, end=length-1, mid;
    while(start <= end){
        mid = start + (end-start)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            start = mid+1;
        }
        else if(arr[mid] > key){
            end = mid-1;
        }
    }

    return -1; // If "key" is not found, -1 will be returned
}
