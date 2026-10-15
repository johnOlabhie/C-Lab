#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    int lineCount = 0;

    // Read input line-by-line until the end of the text/file
    while (getline(cin, line)) {
        lineCount++; // Add 1 to the line count for every line read
    }

    // Print the total number of lines followed by a newline
    cout << lineCount << endl;

    return 0;
}