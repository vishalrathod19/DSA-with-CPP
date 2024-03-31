#include <bits/stdc++.h>
using namespace std;

void solve(string str, vector<string>& ans, int index) {
    // Base case
    if (index >= str.size()) {
        ans.push_back(str);
        return;
    }

    for (size_t i = index; i < str.size(); i++) {
        swap(str[index], str[i]);
        solve(str, ans, index + 1);
        // Backtracking
        swap(str[index], str[i]);
    }
}

vector<string> permutation(string& str) {
    vector<string> ans;
    int index = 0;
    solve(str, ans, index);
    return ans;
}

int main() {
    string str = "abc";
    vector<string> result = permutation(str);

    cout << "All permutations:" << endl;
    for (const auto& perm : result) {
        cout << perm << endl;
    }

    return 0;
}
