#include <iostream>

using namespace std;

int main() {
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;

    // Create a pointer array to hold pointers to different rows
    int** jaggedArray = new int*[rows];

    // Take input for each row size
    int* cols = new int[rows];
    for (int i = 0; i < rows; ++i) {
        cout << "Enter the number of elements in row " << i << ": ";
        cin >> cols[i];

        // Allocate memory for each row
        jaggedArray[i] = new int[cols[i]];

        // Input elements for each row
        cout << "Enter elements for row " << i << ": ";
        for (int j = 0; j < cols[i]; ++j) {
            cin >> jaggedArray[i][j];
        }
    }

    // Displaying the jagged array
    cout << "Jagged Array:" << endl;
    for (int i = 0; i < rows; ++i) {
        cout << "Row " << i << ": ";
        for (int j = 0; j < cols[i]; ++j) {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate memory
    for (int i = 0; i < rows; ++i) {
        delete[] jaggedArray[i];
    }
    delete[] jaggedArray;
    delete[] cols;

    return 0;
}
