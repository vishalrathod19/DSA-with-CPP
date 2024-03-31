#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> nums,vector<vector<int>>&ans,int index){
    //base case 
    if(index>=nums.size())
    {
        ans.push_back(nums);
        return ;
    }
    
    for (size_t i = index; i <nums.size(); i++)
    {
        swap(nums[index],nums[i]);
        solve(nums, ans, index+1);
        //backtracking
        swap(nums[index],nums[i]);
    }
}

vector<vector<int>> permutation(vector<int>&nums)
{
     vector<vector<int>> ans;
     int index = 0;
     solve(nums,ans,index);
     return ans ;
}

int main ()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permutation(nums);

    cout << "All permutations:" << endl;
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;

}