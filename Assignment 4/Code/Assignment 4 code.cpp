#include <iostream>
using namespace std;

// Function to merge two sorted parts of array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left part
    int n2 = right - mid;    // Size of right part

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the two arrays into original
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copy any remaining elements of L[]
    while (i < n1)
        arr[k++] = L[i++];

    // Copy any remaining elements of R[]
    while (j < n2)
        arr[k++] = R[j++];
}

// Function to divide array and call merge
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Same as (left + right)/2 but avoids overflow
        int mid = left + (right - left) / 2;

        // Recursively divide
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main() {
    // Example array
    int arr[] = {5, 2, 9, 1, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, size);

    // Apply merge sort
    mergeSort(arr, 0, size - 1);

    cout << "Sorted Array: ";
    printArray(arr, size);

    // Time complexity comment
    cout << "\nTime Complexity:\n";
    cout << "Best Case: O(n log n)\n";
    cout << "Average Case: O(n log n)\n";
    cout << "Worst Case: O(n log n)\n";

    return 0;
}
