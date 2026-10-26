#include <iostream>
#include <string>
using namespace std;

bool isMatching(char opening, char closing) {
    if (opening == '(' && closing == ')') return true;
    if (opening == '[' && closing == ']') return true;
    if (opening == '{' && closing == '}') return true;

    return false;
}

bool isBalanced(string expression) {
    char stackArr[1000];
    int top = -1;

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            if (top == 999) {
                return false;
            }

            top++;
            stackArr[top] = ch;
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (top == -1) {
                return false;
            }

            if (!isMatching(stackArr[top], ch)) {
                return false;
            }

            top--;
        }
    }

    return top == -1;
}

int main() {
    string expression;

    cout << "Enter an expression without spaces: ";
    cin >> expression;

    if (isBalanced(expression)) {
        cout << "Parentheses are balanced.";
    }
    else {
        cout << "Parentheses are not balanced.";
    }

    return 0;
}
