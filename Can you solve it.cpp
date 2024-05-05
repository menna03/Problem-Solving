#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int a, b;
   cin >> a >> b;
 
    ll result = pow(a, b);
 
    cout << result << endl;
    return 0;
}