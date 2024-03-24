#include<iostream>
#include<vector>

using namespace std ;

int string_compression(vector<char>& ch)
{
    int i  = 0 ;
    int ansIndex = 0;
    int n = ch.size();
    while(i<n)
    {
       int j = i+1;
        while(j<n && ch[i]==ch[j])
        {   
            j++;
        }
        ch[ansIndex++]=ch[i];
        int count = j-i;
        if(count>1)
        {
            string cmt = to_string(count);
            for(char c: cmt)
            {
                ch[ansIndex++]= c;
            }
        }
        i=j;
    }//moving to different character 
   return ansIndex; 
}
int main() {
    string ch = "aabbbccc";
    vector<char> ch_vector(ch.begin(), ch.end());
    int compressed_length = string_compression(ch_vector);
    for (int i = 0; i < compressed_length; ++i) {
        cout << ch_vector[i];
    }
    cout << endl;
    return 0;
}