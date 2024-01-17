#include<iostream>
#include<cstdlib>
#include<bits/stdc++.h>

using namespace std;

void linearsearch(int arr[], int k , int size){
   for (int i = 0; i < size; i++) {
        if (arr[i] == k) {
            cout << k << " is found in the array" << endl;
            return;
        }
    }

    cout << k << " is not found in the array" << endl;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <elemnt1> <element2> <element3> ...... <elementn> <k>" << endl;
        return 1;
    }
    int arr[argc - 1];
    for (int i = 1; i < argc-1; i++) {
        arr[i - 1] = atoi(argv[i]);
    }
    int k= atoi(argv[argc-1]);
    int size = argc-1;
    linearsearch(arr , k , size);
    return 0;
}
