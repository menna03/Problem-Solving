#include <iostream>
#define ll long long
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        ll n;
        cin >> n;
 
        ll currentPowerOf2 = 2;
        ll currentSum = 3;
 
        while (n % currentSum != 0) {
            currentSum += currentPowerOf2 * 2;
            currentPowerOf2 *= 2;
        }
 
        ll x = n / currentSum;
 
        cout << x << '\n';
    }
 
    return 0;
}