#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool knows(vector<vector<int>>& M, int a, int b, int n) {
    return M[a][b] == 1;
}

// Function to find if there is a celebrity in the party or not.
int celebrity(vector<vector<int>>& M, int n) {
    stack<int> s;
    // Step 1: Push all elements into the stack
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    // Step 2: Get 2 elements and compare them
    while (s.size() > 1) {
        int a = s.top();
        s.pop();
        
        int b = s.top();
        s.pop();
        
        if (knows(M, a, b, n)) {
            s.push(b);
        } else {
            s.push(a);
        }
    }

    int candidate = s.top();
    
    // Step 3: Verify the candidate
    // Check row
    int zeroCount = 0;
    for (int i = 0; i < n; i++) {
        if (M[candidate][i] == 0) {
            zeroCount++;
        }
    }
    
    // If the candidate row doesn't have all zeroes (except the candidate itself)
    if (zeroCount != n) {
        return -1;
    }
    
    // Check column
    int oneCount = 0;
    for (int i = 0; i < n; i++) {
        if (M[i][candidate] == 1) {
            oneCount++;
        }
    }
    
    // If the candidate column doesn't have all ones (except the candidate itself)
    if (oneCount != n - 1) {
        return -1;
    }
    
    return candidate;
}

int main() {
    int n;
    cout << "Enter the number of people at the party: ";
    cin >> n;

    vector<vector<int>> M(n, vector<int>(n));
    cout << "Enter the matrix (1 if a person knows the other person, otherwise 0):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }

    int result = celebrity(M, n);
    if (result == -1) {
        cout << "There is no celebrity in the party." << endl;
    } else {
        cout << "The celebrity is person " << result << "." << endl;
    }

    return 0;
}
