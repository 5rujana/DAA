#include<iostream>
#include<algorithm>

using namespace std;

int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
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

    sort(arr, arr + size);

    int result = binarySearch(arr, size, key);

    if (result != -1) {
        cout << key << " is found in the array at index " << result << endl;
    } else {
        cout << key << " is not found in the array" << endl;
    }

    return 0;
}
