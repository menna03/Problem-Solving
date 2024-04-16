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
    ll factorial  = 1.0;
    for(int i = 1; i <= t; ++i) {
        factorial *= i;
    }
    cout<<factorial;
    return 0;
}