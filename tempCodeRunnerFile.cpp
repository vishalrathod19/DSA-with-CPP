#include <iostream>

int main() {
    // Asking user for the number of rows in the jagged array
    int num_rows;
    std::cout << "Enter the number of rows: ";
    std::cin >> num_rows;

    // Dynamically allocating an array of pointers to int to store the sub-arrays
    int **jagged_array = new int*[num_rows];

    // Asking user for the size of each row
    for (int i = 0; i < num_rows; ++i) {
        int row_size;
        std::cout << "Enter the size of row " << i << ": ";
        std::cin >> row_size;

        // Dynamically allocating memory for each row based on user input
        jagged_array[i] = new int[row_size];

        // Asking user to input values for each element in the row
        std::cout << "Enter " << row_size << " elements for row " << i << ":\n";
        for (int j = 0; j < row_size; ++j) {
            std::cin >> jagged_array[i][j];
        }
    }

    // Displaying the jagged array
    std::cout << "\nJagged Array:\n";
    for (int i = 0; i < num_rows; ++i) {
        int row_size = sizeof(jagged_array[i]) / sizeof(jagged_array[i][0]);
        std::cout << "Row " << i << ": ";
        for (int j = 0; j < row_size; ++j) {
            std::cout << jagged_array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Freeing dynamically allocated memory
    for (int i = 0; i < num_rows; ++i) {
        delete[] jagged_array[i];
    }
    delete[] jagged_array;

    return 0;
}
