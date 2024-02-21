#include <iostream>
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
ll factorial(int N) {
    if (N == 1) {
        return 1;
    } else {
        return N * factorial(N - 1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int t;
    cin >> t;
 
    queue<int> myQueue;
 
    while (t--) {
        string query;
        cin >> query;
 
        if (query == "push") {
            int x;
            cin >> x;
            myQueue.push(x);
        } else if (query == "pop") {
            myQueue.pop();
        } else if (query == "front") {
            cout << myQueue.front() << endl;
        } else if (query == "back") {
            cout << myQueue.back() << endl;
        }
    }
 
    return 0;
}