#include <iostream>
#include <vector>

void add_array(int arr1[], int arr2[], int n, int m) {
    int carry = 0;
    int max_len = std::max(n, m);
    std::vector<int> result(max_len + 1, 0); // Extra space for potential carry

    int i = n - 1, j = m - 1, k = max_len;

    while (i >= 0 || j >= 0) {
        int sum = carry;
        if (i >= 0) sum += arr1[i];
        if (j >= 0) sum += arr2[j];

        carry = sum / 10;
        result[k] = sum % 10;
        
        i--;
        j--;
        k--;
    }
    
    result[0] = carry; // Store any remaining carry in the first element
    
    // Print the result array
    for (int i = 0; i <= max_len; i++) {
        std::cout << result[i] << " ";
    }
}

int main() {
    int arr1[1] = {9};
    int arr2[3] = {9, 9, 9};
    add_array(arr1, arr2, 1, 3);
    return 0;
}
