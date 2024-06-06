#include <iostream>

int findDuplicate(int arr[], int size) 
{
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return arr[i];
            }
        }
    }
    
    // If no duplicate found
    return -1;
}

int main() {
    // Test case
    int nums[] = {1, 2, 3, 4, 5, 5}; // Duplicate is 5
    int size = sizeof(nums) / sizeof(nums[0]);
    
    int duplicate = findDuplicate(nums, size);
    if (duplicate != -1) {
        std::cout << "Duplicate element is: " << duplicate << std::endl;
    } else {
        std::cout << "No duplicate found." << std::endl;
    }
    
    return 0;
}
