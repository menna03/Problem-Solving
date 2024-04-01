#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    
    int n, k;
    cin >> n >> k;
 
    vector<int> problems(n);
    for (int i = 0; i < n; ++i) {
        cin >> problems[i];
    }
 
    int left = 0, right = n - 1;
    int solvedProblems = 0;
 
    while (left <= right) {
        if (problems[left] <= k) {
            ++solvedProblems;
            ++left;
        } else if (problems[right] <= k) {
            ++solvedProblems;
            --right;
        } else {
            break;
        }
    }
 
    cout << solvedProblems << endl;
    return 0;
}