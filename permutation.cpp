#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

void generatePermutations(const vector<char>& elements, vector<char>& current, vector<bool>& used) {
    if (current.size() == elements.size()) {
        // Display the current permutation
        for (char ch : current) {
            cout << ch << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < elements.size(); ++i) {
        if (!used[i]) {
            // Include the element at index i in the current permutation
            current.push_back(elements[i]);
            used[i] = true;

            // Recursively generate permutations
            generatePermutations(elements, current, used);

            // Backtrack: remove the last element and mark it as unused
            current.pop_back();
            used[i] = false;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <element1> <element2> ... <elementN>" << endl;
        return 1;
    }

    vector<char> elements;
    for (int i = 1; i < argc; ++i) {
        elements.push_back(argv[i][0]);
    }

    vector<char> current;
    vector<bool> used(elements.size(), false);

    cout << "All permutations without repetition:" << endl;
    generatePermutations(elements, current, used);

    return 0;
}
