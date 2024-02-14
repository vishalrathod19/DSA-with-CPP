#include <iostream>
#include <vector>

using namespace std;

void move_zero(vector<int>& arr) {
    int i = 0;
    for (int j = 0; j < arr.size(); j++) {
        if (arr[j] != 0) {
            swap(arr[j], arr[i]);
            i++;
        }
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    
    cout << "Original Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    move_zero(nums);
    
    cout << "Array after moving zeros to the end: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
