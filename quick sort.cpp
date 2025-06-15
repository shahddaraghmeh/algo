#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstring>
// Swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Data generation functions
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

// Print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int size, type;

   size=20000;

    // ?? Using Variable Length Array (VLA)
    int arr[size];
// Choose one of: "random", "sorted", "reverse","partially_sorted"
    generateTestData(arr, size, "partially_sorted");
 printf("\nunSorted array:\n");
    printArray(arr, size);
    quickSort(arr, 0, size - 1);

    printf("\nSorted array:\n");
    printArray(arr, size);

    return 0;
}
