#include <iostream>
#include <set>

void findUniqueElements(int arr[], int size) {
    std::set<int> uniqueElements(arr, arr + size);

    std::cout << "Unique elements in the array are: ";
    for (int elem : uniqueElements) {
        std::cout << elem << " ";
    }
}

int main() {
    int arr[10] = {1, 2, 2, 3, 4, 4, 5, 6, 6, 7};

    findUniqueElements(arr, 10);

    return 0;
}
