#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int q;
    cin >> q;
 
    stack<int> myStack;
 
    while (q--) {
        string query;
        cin >> query;
 
        if (query == "push") {
            int x;
            cin >> x;
            myStack.push(x);
        } else if (query == "pop") {
            myStack.pop();
        } else if (query == "top") {
            cout << myStack.top() << endl;
        }
    }
 
    return 0;
}