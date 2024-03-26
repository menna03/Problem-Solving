#include <iostream>
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
 
    for (int i = t; i >= 1; --i) {
        cout << i;
        if (i > 1) {
            cout << " ";
        }
    }  return 0;
}