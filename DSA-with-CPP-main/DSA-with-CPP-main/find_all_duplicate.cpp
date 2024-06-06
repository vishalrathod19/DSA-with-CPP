#include <iostream>
using namespace std;

void findDuplicates(int arr[], int n) {
    cout << "Duplicate elements in the array are: ";
    for (int i = 0; i < n; i++) { // Loop through all elements of the array
        for (int j = i + 1; j < n; j++) { // Start another loop from the next element
            if (arr[i] == arr[j]) { // If current element matches with any other element
                cout << arr[i] << " "; // Print the duplicate element
                break; // Exit the loop
            }
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 5, 3}; // Your array
    int n = sizeof(arr) / sizeof(arr[0]); // Size of the array

    findDuplicates(arr, n); // Calling the function to find duplicates

    return 0;
}
