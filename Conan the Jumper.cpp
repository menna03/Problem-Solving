#include <iostream>
using namespace std;
 
int main() {
    long long  x, y;
    cin >> x >> y;
 
    long long j = 0;
 
    while (y > x) {
        if (y % 2 != 0) {
            y++;
            j++;
        }
        y /= 2;
        j++;
    }
 
    j += x - y;
 
    cout << j << endl;
 
    return 0;
}