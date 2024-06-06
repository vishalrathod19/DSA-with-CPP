#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{   int mid = s+(e-s)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];
    // copy the elements
    int mainarrayindex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainarrayindex++];
    }
    mainarrayindex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainarrayindex++];
    }

    // merge 2 sorted array
    int index1 = 0;
    int index2 = 0;
    mainarrayindex = s;
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainarrayindex++] = first[index1++];
        }
        else
        {
            arr[mainarrayindex++] = second[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[mainarrayindex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainarrayindex++] = second[index2++];
    }
    delete[] first;
    delete[] second;
}
void merge_sort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    //rightside
    merge_sort(arr, s, mid);
    //leftside
    merge_sort(arr, mid + 1, e);
    merge(arr, s, e);
}
int main()
{
    int arr[5] = {5, 2, 9, 3, 8};
    int n = 5;
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}