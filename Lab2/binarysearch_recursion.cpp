#include<iostream>
#include<algorithm>

using namespace std;

int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            return binarySearchRecursive(arr, mid + 1, high, key);
        } else {
            return binarySearchRecursive(arr, low, mid - 1, key);
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <element1> <element2> <element3> ... <elementn> <k>" << endl;
        return 1;
    }

    int arr[argc - 1];
    for (int i = 1; i < argc - 1; i++) {
        arr[i - 1] = atoi(argv[i]);
    }

    int size = argc - 1;
    int key = atoi(argv[argc - 1]);

    // Binary search assumes that the array is sorted, so let's sort it first
    sort(arr, arr + size);

    int result = binarySearchRecursive(arr, 0, size - 1, key);

    if (result != -1) {
        cout << key << " is found in the array at index " << result << endl;
    } else {
        cout << key << " is not found in the array" << endl;
    }

    return 0;
}
