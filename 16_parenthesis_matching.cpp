#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isBalanced(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) return false;   
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;               // wrong type of bracket
            }
        }
    }
  return st.empty();   // balanced only if nothing is left over
}

int main() {
    string s;
    cout << "Enter expression: ";
    cin >> s;
    if (isBalanced(s))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
    return 0;
}
