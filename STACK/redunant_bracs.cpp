#include <iostream>
#include <stack>
using namespace std;

bool result(string &s){
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        char ch = s[i];

        // push opening bracket and operators
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else if(ch == ')'){
            bool redt = true;

            // check if any operator exists inside the brackets
            while(!st.empty() && st.top() != '('){
                char top = st.top();
                if(top == '+' || top == '-' || top == '*' || top == '/'){
                    redt = false;
                }
                st.pop();
            }

            // pop the '('
            if(!st.empty()) st.pop();

            // if no operator inside, brackets are redundant
            if(redt) return true;
        }
    }
    return false; // no redundant brackets found
}

int main(){
    string str = "((a+b))";
    if(result(str)){
        cout << "true";
    }
    else{
        cout << "false";
    }
    return 0;
}
