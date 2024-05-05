#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string m;
    cin >> m;
 
    stack<char> p;
    p.push(m[0]);
 
    if (m.length() % 2) {
        cout << "No" << endl;
        return 0;
    }
 
    for (size_t i = 1; i < m.length(); i++) {
        if (p.empty() || m[i] != p.top())
            p.push(m[i]);
        else
            p.pop();
    }
 
    if (p.empty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
 
    return 0;
}