#include<iostream>
#include<cstdlib>

using namespace std;

void hanoi(int n, char source, char auxiliary, char target) {
    if (n > 0) {
        // Move n-1 disks from source to auxiliary peg
        hanoi(n - 1, source, target, auxiliary);

        // Move the nth disk from source to target peg
        cout << "Move disk " << n << " from " << source << " to " << target << endl;

        // Move the n-1 disks from auxiliary to target peg
        hanoi(n - 1, auxiliary, source, target);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <number_of_disks>" << endl;
        return 1;
    }

    int numDisks = atoi(argv[1]);

    if (numDisks <= 0) {
        cout << "Please enter a positive number of disks." << endl;
        return 1;
    }

    cout << "Towers of Hanoi steps for " << numDisks << " disks:" << endl;
    hanoi(numDisks, 'A', 'B', 'C');

    return 0;
}
