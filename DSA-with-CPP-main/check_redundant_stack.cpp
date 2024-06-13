#include<iostream>
#include<stack>
using namespace std;

bool findRedundantBrackets(string &s){
    stack<char> st;
    for(int i = 0 ; i<s.length();i++)
    {
        char ch = s[i];
        if(ch == '('||ch == '+'||ch == '-'||ch == '*'||ch == '/'){
            st.push(ch);
        }
        else{
            if(ch == ')'){
                bool isRedundant = true;
                while(st.top() != '('){
                    char top = st.top();
                    if(top == '+'||top == '-'||top == '*'||top == '/'){
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant == true){
                    return true;
                }
               st.pop(); 
        }
    }
 }
 return false;
}
int main() {
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;

    if (findRedundantBrackets(expression)) {
        cout << "The expression has redundant brackets.\n";
    } else {
        cout << "The expression does not have redundant brackets.\n";
    }

    return 0;
}