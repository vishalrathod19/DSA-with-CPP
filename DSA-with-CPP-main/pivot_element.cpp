#include <iostream>
using namespace std;

int Pivot(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    
    // Perform binary search to find the pivot element
    while (start < end) {
        int mid = (start + end) / 2;
        
        // If the middle element is greater than or equal to the first element,
        // pivot must be on the right side
        if (arr[mid] >= arr[0]) {
            start = mid + 1;
        } else { // Otherwise, pivot must be on the left side
            end = mid;
        }
    }
    
    // At the end of the loop, 'start' will point to the pivot element
    return start;
}

int main() {
    int arr[5] = {12,15,18,2,4};
    
    // Find the pivot element
    int result = Pivot(arr, 5);
    
    // Print the index of the pivot element
    cout << "The pivot element is at index: " << result << endl;
    
    return 0;
}
