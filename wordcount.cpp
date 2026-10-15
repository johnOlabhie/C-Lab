#include <iostream>
#include <string>

using namespace std;

int main() {
    int wordCount = 0;
    string word;

    // This loop reads text word-by-word until the end of the input stream
    while (cin >> word) {
        wordCount++; // Add 1 to the count for every word found
    }

    // Print the final total count followed by a newline
    cout << wordCount << endl;

    return 0;
}