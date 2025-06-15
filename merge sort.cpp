#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to merge two halves of the array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;    // Size of right subarray

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copy remaining elements of L[] if any
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Copy remaining elements of R[] if any
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the middle point

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to generate test data based on the specified pattern
void generateTestData(int arr[], int size, const char* pattern) {
    if (strcmp(pattern, "random") == 0) {
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 10000; // Random values between 0 and 9999
        }
    } else if (strcmp(pattern, "sorted") == 0) {
        for (int i = 0; i < size; i++) {
            arr[i] = i; // Already sorted array
        }
    } else if (strcmp(pattern, "reverse") == 0) {
        for (int i = 0; i < size; i++) {
            arr[i] = size - i; // Reverse sorted array
        }
    } else if (strcmp(pattern, "partially_sorted") == 0) {
        for (int i = 0; i < size; i++) {
            if (i < size / 2)
                arr[i] = i; // First half sorted
            else
                arr[i] = rand() % 1000; // Second half random
        }
    } else {
        printf("Unknown pattern: %s\n", pattern);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size = 100000; // Size of the array
    int arr[size];    // Declare the array

    srand(time(NULL)); // Seed for random number generation

    // Choose one of the following patterns: "random", "sorted", "reverse", "partially_sorted"
    generateTestData(arr, size, "random");

    printf("\nUnsorted array:\n");
    printArray(arr, size);

    mergeSort(arr, 0, size - 1); // Call Merge Sort

    printf("\nSorted array:\n");
    printArray(arr, size);

    return 0;
}
