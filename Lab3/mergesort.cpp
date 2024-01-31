#include <iostream>
#include <cstdlib>

using namespace std;

void merge(int arr[], int low, int middle, int high) {
    int n1 = middle - low + 1;
    int n2 = high - middle;

    // Create temporary arrays
    int leftArray[n1];
    int rightArray[n2];

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[middle + 1 + j];

    // Merge the temporary arrays back into arr[low..high]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = low; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray[], if there are any
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if there are any
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int middle = low + (high - low) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, low, middle);
        mergeSort(arr, middle + 1, high);

        // Merge the sorted halves
        merge(arr, low, middle, high);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <space-separated list of numbers>\n";
        return 1;
    }

    int size = argc - 1;
    int arr[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = atoi(argv[i + 1]);
    }

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
