#include <iostream>
#include <bits/stdc++.h>
 
#include <algorithm>
#define ll long long
using namespace std;
ll n,  x,  y,  z;
ll shawerma() {
    ll dp[n + 1];
    dp[0] = 0;
 
    for (int i = 1; i <= n; ++i) {
        dp[i] = -1;
        if (i >= x) {
            dp[i] = max(dp[i], dp[i - x]);
        }
        if (i >= y) {
            dp[i] = max(dp[i], dp[i - y]);
        }
        if (i >= z) {
            dp[i] = max(dp[i], dp[i - z]);
        }
        if (dp[i] != -1) {
            dp[i]++;
        }
    }
 
    return dp[n];
}int main() {
    cin >> n >> x >> y >> z;
 
    ll result = shawerma();
    cout << result << endl;
 
    return 0;
}