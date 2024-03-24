#include <iostream>
#include <algorithm>

using namespace std;

// Function to reverse a word
void reverseWord(string& word) {
    int left = 0;
    int right = word.length() - 1;

    while (left < right) {
        swap(word[left], word[right]);
        left++;
        right--;
    }
}

// Function to reverse words in a string
string reverseStringWords(string str) {
    string reversedString = "";
    string word = "";

    for (char& c : str) {
        if (c == ' ') {
            reverseWord(word);
            reversedString += word + ' ';
            word = "";
        } else {
            word += c;
        }
    }

    reverseWord(word); // Reverse the last word
    reversedString += word;

    return reversedString;
}

int main() {
    string inputString = "school was good";
    string reversedWords = reverseStringWords(inputString);
    cout << "Reversed Words: " << reversedWords << endl;
    return 0;
}
