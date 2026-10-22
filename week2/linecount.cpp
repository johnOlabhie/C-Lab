#include <iostream>
#include <string>

using namespace std;

int main() {
    int lineCount = 0;
    string line;

    // This loop reads text line-by-line until the end of the input stream
    while (getline(cin, line)) {
        lineCount++;
    }
    
    cout << lineCount << '\n';

    return 0;
}

/*pRT 3

#include <iostream>
#include <string>

using namespace std;

int main() {
    string longest = "";
    string line;

    // This loop reads text line-by-line until the end of the input stream
    while (getline(cin, line)) {
        // If the current line is longer than our saved longest line, update it
        if (line.size() > longest.size()) {
            longest = line;
        }
    }
    
    cout << longest << '\n';

    return 0;
}





*/