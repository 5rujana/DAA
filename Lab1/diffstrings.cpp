#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

void generateStrings(const vector<char>& characters, int k, string& current) {
    if (current.length() == k) {
        cout << current << endl;
        return;
    }

    for (char ch : characters) {
        // Include the character in the current string
        current.push_back(ch);

        // Recursively generate strings
        generateStrings(characters, k, current);

        // Backtrack: remove the last character
        current.pop_back();
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " <character1> <character2> ... <characterN> <k>" << endl;
        return 1;
    }

    vector<char> characters;
    for (int i = 1; i < argc - 1; ++i) {
        characters.push_back(argv[i][0]);
    }

    int k = atoi(argv[argc - 1]);

    if (k <= 0) {
        cout << "Please enter a positive value for k." << endl;
        return 1;
    }

    string current;
    cout << "All possible strings of length " << k << ":" << endl;
    generateStrings(characters, k, current);

    return 0;
}
