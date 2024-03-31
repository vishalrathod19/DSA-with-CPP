#include<bits/stdc++.h>
using namespace std;

void solve(string digits , string output , vector<string> & ans , int index , string mapping[])
{
    //base case 
    if(digits.length()<=index){
        ans.push_back(output);
        return ;
    }
    
    int number = digits[index]-'0';
    string value = mapping[number];
    for (size_t i = 0; i < value.length(); i++)
    {
        /* code */
        output.push_back(value[i]);
        solve(digits, output, ans, index+1, mapping);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string>ans ;
    if(digits.length()==0)
    {
        return ans ;
    }
    string output ;
    int index = 0 ;
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(digits,output,ans,index,mapping);
    return ans ;
}

int main() {
    string digits = "32";
    vector<string> combinations = letterCombinations(digits);
    
    cout << "Letter combinations for digits \"" << digits << "\":" << endl;
    for (const string &combination : combinations) {
        cout << combination << endl;
    }

    return 0;
}