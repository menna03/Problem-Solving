#include <iostream>
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int sequence(int n) {
    if (n == 1) {
        return 1;
    } else if (n % 2 == 0) {
        return 1 + sequence(n / 2);
    } else {
        return 1 + sequence(3 * n + 1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
 
    int result = sequence(t);
    cout << result << endl;
 
    return 0;
}