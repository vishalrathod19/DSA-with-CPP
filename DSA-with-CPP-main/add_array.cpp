#include <iostream>
using namespace std;

void add_array(int arr1[], int arr2[], int n, int m) {
    int i = n - 1;
    int j = m - 1;
    int carry = 0;
    int k = max(n, m); // Use the larger size for the result array
    int result[k]; // Array to store the result
    
    while (i >= 0 && j >= 0) {
        int sum = arr1[i] + arr2[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        result[k-1] = sum; // Store the digit from right to left
        i--;
        j--;
        k--;
    }
    
    while (i >= 0) {
        int sum = arr1[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        result[k-1] = sum;
        i--;
        k--;
    }
    
    while (j >= 0) {
        int sum = arr2[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        result[k-1] = sum;
        j--;
        k--;
    }
    
    if (carry != 0) {
        cout << carry << " "; // Print the carry if it's not zero
    }
    
    // Print the result array
    for (int i = 0; i < max(n, m); i++) {
        cout << result[i] << " ";
    }
}

int main() {
    int arr1[1] = {9};
    int arr2[3] = {9, 9, 9};
    add_array(arr1, arr2, 1, 3);
    return 0;
}
