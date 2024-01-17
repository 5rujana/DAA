#include<iostream>
#include<cstdlib>

using namespace std;

int linearSearchRecursive(int arr[], int N, int i, int X) {
    if (i == N) {
        return -1;
    } else if (arr[i] == X) {
        return i;
    } else {
        return linearSearchRecursive(arr, N, i + 1, X);
    }
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

    int k = atoi(argv[argc - 1]);
    int size = argc - 1;

    int result = linearSearchRecursive(arr, size, 0, k);

    if (result != -1) {
        cout << k << " is found in the array at index " << result << endl;
    } else {
        cout << k << " is not found in the array" << endl;
    }

    return 0;
}
