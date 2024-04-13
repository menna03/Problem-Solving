#include <iostream>
 
#define ll long long
using namespace std;
 
const int MOD = 1e9 + 7;
 
ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll x;
    cin >> x;
 
    ll y = 0;
    ll temp = x;
    while (temp > 0) {
        y = y * 10 + temp % 10;
        temp /= 10;
    }
 
    ll powXY = mod_pow(x, y, MOD);
    ll powYX = mod_pow(y, x, MOD);
 
    if (powXY > powYX) {
        cout << "Alice\n";
    } else if (powXY < powYX) {
        cout << "Bob\n";
    } else {
        cout << "Draw\n";
    }
 
    return 0;
}