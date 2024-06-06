#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void solve(vector<int>& nums, vector<int> output, int index, vector<vector<int>>& ans) {
        // Base case
        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }
        // Exclude the current element
        solve(nums, output, index + 1, ans);
        // Include the current element
        output.push_back(nums[index]);
        solve(nums, output, index + 1, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, output, index, ans); 
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> subsets = sol.subsets(nums);

    // Print the subsets
    for (const auto& subset : subsets) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1) {
                cout << ", ";
            }

        }
        cout << "]" << endl;
    }

    return 0;
}
