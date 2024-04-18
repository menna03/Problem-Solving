#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int countPairs(int n, int x, vector<int>& a) {
    int pairsCount = 0;
    int i = 0;
 
    while (i < n - 1) {
        int j = i + 1;
 
        while (j < n) {
            if ((a[i] + a[j]) <= x && a[i] >= i + 1 && a[j] >= j + 1)
                pairsCount++;
 
            j++;
        }
 
        i++;
    }
 
    return pairsCount;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int n, x;
    cin >> n >> x;
 
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    int result = countPairs(n, x, a);
    cout << result << endl;
 
    return 0;
}