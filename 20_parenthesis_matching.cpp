#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string s) {
    stack<char> st;

    for (char c : s) {
        // opening bracket -> push
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        // closing bracket -> check with top of stack
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) return false;   // nothing to match with

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
