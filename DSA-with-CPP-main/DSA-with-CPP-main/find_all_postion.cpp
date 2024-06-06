#include <iostream>

using namespace std;

int binarySearchFirst(int nums[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int firstPos = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            firstPos = mid;
            right = mid - 1; // continue searching in the left subarray
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return firstPos;
}

int binarySearchLast(int nums[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int lastPos = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            lastPos = mid;
            left = mid + 1; // continue searching in the right subarray
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return lastPos;
}

int main() {
    int nums[] = {1, 2, 2, 2, 3, 3, 3, 4, 5, 6, 6, 6};
    int size = sizeof(nums) / sizeof(nums[0]);
    int target = 2;

    int firstPos = binarySearchFirst(nums, size, target);
    int lastPos = binarySearchLast(nums, size, target);

    if (firstPos != -1 && lastPos != -1) {
        cout << "Occurrences of " << target << " are at indices: ";
        for (int i = firstPos; i <= lastPos; ++i) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
