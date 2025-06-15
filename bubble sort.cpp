#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate test data
void generateTestData(int arr[], int size, const char* pattern) {
    int i;

    if (strcmp(pattern, "random") == 0) {
        for (i = 0; i < size; i++) {
            arr[i] = rand() % 10000; // Random values between 0-999
        }
    } else if (strcmp(pattern, "sorted") == 0) {
        for (i = 0; i < size; i++) {
            if (i < size )
                arr[i] = i; 
          
        }
    } else if (strcmp(pattern, "partially_sorted") == 0) {
        for (i = 0; i < size; i++) {
            if (i < size /2)
                arr[i] = i; // First half sorted
          else arr[i]=rand()%1000;
        }}else if (strcmp(pattern, "reverse") == 0) {
        for (i = 0; i < size; i++) {
            arr[i] = size - i;
        }
    } else {
        printf("Unknown pattern: %s\n", pattern);
    }
}

// Function to sort array using Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapcount;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
        	swapcount=0;
            if (arr[j] > arr[j + 1]) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapcount++;
            }
            
        }
        if(swapcount==0){ break;
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Main function
int main() {
    srand(time(NULL)); // Initialize random seed

    int size =20000; // Change this to 10, 100, 1000 as needed
    int arr[size]; // Make sure size = 1000

    // Choose one of: "random", "sorted", "reverse","partially_sorted"
    generateTestData(arr, size, "random");

   printf("Array before sorting:\n");
    printArray(arr, size);

    bubbleSort(arr, size);

    printf("Array after Bubble Sort:\n");
    printArray(arr, size);

    return 0;
}
