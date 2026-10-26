
#include <iostream>
#include <stack>
using namespace std;

// move the top disk from one stack to another
void moveDisk(stack<int> &from, stack<int> &to, char f, char t) {
    int disk = from.top();   // look at top disk
    from.pop();              // remove it
    to.push(disk);           // place it on the other peg
    cout << "Move disk " << disk << " from " << f << " to " << t << endl;
}

void hanoi(int n, stack<int> &from, stack<int> &to, stack<int> &helper,
           char f, char t, char h) {
    if (n == 0) return;

    hanoi(n - 1, from, helper, to, f, h, t);   // n-1 disks: source -> helper
    moveDisk(from, to, f, t);                  // biggest disk: source -> target
    hanoi(n - 1, helper, to, from, h, t, f);   // n-1 disks: helper -> target
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    stack<int> A, B, C;

    // put disks on A: biggest (n) at bottom, smallest (1) on top
    for (int i = n; i >= 1; i--)
        A.push(i);

    hanoi(n, A, C, B, 'A', 'C', 'B');

    cout << "Disks now on C: " << C.size() << endl;
    return 0;
}
