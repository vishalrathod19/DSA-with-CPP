#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool ifsafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& m) {
        if (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && m[x][y] == 1) {
            return true;
        } else {
            return false;
        }
    }

    void solve(vector<vector<int>>& m, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path) {
        //base case
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }
        visited[x][y] = 1;
        
        //down case 
        int newx = x + 1;
        int newy = y;
        if (ifsafe(newx, newy, n, visited, m)) {
            path.push_back('D'); // 'D' for down
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        
        //left
        newx = x;
        newy = y - 1;
        if (ifsafe(newx, newy, n, visited, m)) {
            path.push_back('L'); // 'L' for left
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        
        //right
        newx = x;
        newy = y + 1;
        if (ifsafe(newx, newy, n, visited, m)) {
            path.push_back('R'); // 'R' for right
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        
        newx = x - 1;
        newy = y;
        if (ifsafe(newx, newy, n, visited, m)) {
            path.push_back('U'); // 'U' for up
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        visited[x][y] = 0; // Corrected from '==' to '='
    }

public:
    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> ans;
        int srcx = 0;
        int srcy = 0;
        if (m[0][0] == 0) {
            return ans;
        }
        vector<vector<int>> visited=m;
         for(int i = 0 ; i<n ;i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                visited[i][j]=0;
            }
        } // Initialize visited matrix correctly
        string path = "";
        solve(m, n, ans, srcx, srcy, visited, path);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> matrix = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    vector<string> paths = sol.findPath(matrix, n);
    cout << "Possible Paths:\n";
    for (const string& path : paths) {
        cout << path << '\n';
    }
    return 0;
}
