#include <iostream>
#include <string>

using namespace std;

string removeAdjacentDuplicates(string s) {
    int n = s.length();
    int j = 0;

    // Iterate through the string
    for (int i = 0; i < n; i++) {
        // If the current character is not equal to the next character
        // or if it's the first character
        if (i == n - 1 || s[i] != s[i + 1]) {
            // Store the character at position i
            s[j++] = s[i];
        } else {
            // Skip the next character as it's a duplicate
            i++;
        }
    }

    // Resize the string to the new length after removing duplicates
    s.resize(j);

    return s;
}

int main() {
    string input = "xxcaayx";
    string result = removeAdjacentDuplicates(input);
    cout << "String after removing adjacent duplicates: " << result << endl;

    return 0;
}
