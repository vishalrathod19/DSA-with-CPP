#include <bits/stdc++.h>

using namespace std;

void rotateMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // Transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Reverse each row to rotate by 90 degrees clockwise
    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3},
                                   {4, 5, 6},
                                   {7, 8, 9}};
    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    rotateMatrix(matrix);

    cout << "\nMatrix after 90 degree rotation:" << endl;
    printMatrix(matrix);

    return 0;
}
