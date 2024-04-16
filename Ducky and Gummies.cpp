#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
 
using namespace std;
 
ll money, n;
vector<ll> prices;
vector<ll> bubble_sizes;
 
ll max_bubble_size() {
    ll n = prices.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(money + 1, 0));
 
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= money; ++j) {
            if (prices[i - 1] <= j) {
                //knapsack problem.
                dp[i][j] = max(dp[i - 1][j], bubble_sizes[i - 1] + dp[i - 1][j - prices[i - 1]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][money];
}
 
int main() {
    cin >> money >> n;
 
    prices.resize(n);
    bubble_sizes.resize(n);
 
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
 
    for (int i = 0; i < n; ++i) {
        cin >> bubble_sizes[i];
    }
 
    ll result = max_bubble_size();
    cout << result << endl;
 
    return 0;
}
