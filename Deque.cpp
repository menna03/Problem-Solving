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
 
    deque<int> deque;
 
    while (q--) {
        string query;
        cin >> query;
 
        if (query == "push_back") {
            int x;
            cin >> x;
            deque.push_back(x);
        } else if (query == "push_front") {
            int x;
            cin >> x;
            deque.push_front(x);
        } else if (query == "pop_front") {
            deque.pop_front();
        } else if (query == "pop_back") {
            deque.pop_back();
        } else if (query == "front") {
            cout << deque.front() << endl;
        } else if (query == "back") {
            cout << deque.back() << endl;
        } else if (query == "print") {
            int x;
            cin >> x;
            cout << deque[x - 1] << endl;
        }
    }
    return 0;
}