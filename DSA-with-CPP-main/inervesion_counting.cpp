#include <iostream>
using namespace std;

long long merge(int *arr, int s, int mid, int e) {
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *left = new int[len1];
    int *right = new int[len2];

    for (int i = 0; i < len1; i++)
        left[i] = arr[s + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = s;
    long long inv_count = 0;

    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            inv_count += len1 - i; // Count inversions when an element from right subarray is smaller
        }
    }

    while (i < len1) arr[k++] = left[i++];
    while (j < len2) arr[k++] = right[j++];

    delete[] left;
    delete[] right;

    return inv_count;
}

long long merge_sort(int *arr, int s, int e) {
    long long inv_count = 0;
    if (s < e) {
        int mid = s + (e - s) / 2;
        inv_count += merge_sort(arr, s, mid);
        inv_count += merge_sort(arr, mid + 1, e);
        inv_count += merge(arr, s, mid, e);
    }
    return inv_count;
}

int main() {
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    long long inversions = merge_sort(arr, 0, n - 1);

    cout << "Inversion count: " << inversions << endl;

    return 0;
}
