#include <iostream>
#include <cstdlib>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;

            // Swap arr[i] and arr[j]
            swap(arr[i], arr[j]);
        }
    }

    // Swap arr[i+1] and arr[high] (put the pivot element in its correct position)
    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partitioning index is the index where the pivot element is
        int pi = partition(arr, low, high);

        // Recursively sort the elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <space-separated list of numbers>\n";
        return 1;
    }

    int size = argc - 1;
    int arr[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = std::atoi(argv[i + 1]);
    }

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    quickSort(arr, 0, size - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
