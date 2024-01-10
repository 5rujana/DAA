#include<iostream>
#include<cstdlib>
using namespace std;

int fibonacci(int n, int &calls) {
    calls++;  // Increment the count of function calls
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1, calls) + fibonacci(n - 2, calls);
    }
}

void printFibonacciSeries(int n) {
    int calls = 0;  // Variable to store the count of function calls
    cout << "Fibonacci Series for n = " << n << ": ";
    for (int i = 0; i < n; ++i) {
        int result = fibonacci(i, calls);
        cout << result << " ";
    }
    cout << endl;
    cout << "Number of function calls: " << calls << endl;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <n>" << endl;
        return 1;
    }

    int n = atoi(argv[1]);

    printFibonacciSeries(n);

    return 0;
}
