#include <iostream>
#include <string>

using namespace std;

int main() {
    int wordCount = 0;
    string word;

    // This loop reads text word-by-word until the end of the input stream
    while (cin >> word) {
        wordCount++;
    }
    
    cout << wordCount << '\n';

    return 0;
}