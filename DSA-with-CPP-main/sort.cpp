#include<iostream>
using namespace std;

// Function to print the elements of an array
void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to sort an array containing only 0s and 1s
void sortOne(int arr[], int n) {

    int left = 0, right = n-1;

    while(left < right) {

        // Move left pointer to the right until it finds a 1
        while(arr[left] == 0 && left < right )  {
            left++;
        }

        // Move right pointer to the left until it finds a 0
        while(arr[right]==1 && left < right){
            right--;
        }

        // If left pointer is still less than right pointer, swap the elements
        if(left < right)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

// Main function
int main() {

    // Initializing an array containing 0s and 1s
    int arr[8] = {1, 1, 0, 0, 0, 0, 1, 0};

    // Calling sortOne function to sort the array
    sortOne(arr, 8);

    // Printing the sorted array
    printArray(arr, 8);

    return 0;
}
