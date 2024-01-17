#include<iostream>
#include<cstdlib>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <num>" << endl;
        return 1;
    }

    int num = atoi(argv[1]);

    if (num < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
        return 1;
    }

    int result = factorial(num);

    cout << "Factorial of " << num << " is: " << result << endl;

    return 0;
}
