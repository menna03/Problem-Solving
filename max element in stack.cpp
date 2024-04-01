#include <iostream>
#include <stack>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    stack<long long> s;
    long long currentMax = LLONG_MIN;
 
    for (int i = 0; i < n; ++i) {
        int operation;
        cin >> operation;
 
        if (operation == 1) {
            long long x;
            cin >> x;
            if (x > currentMax) {
                currentMax = x;
            }
            s.push(x);
        } else if (operation == 2 && !s.empty()) {
            long long removed = s.top();
            s.pop();
            if (removed == currentMax && !s.empty()) {
                currentMax = s.top();
                stack<long long> tempStack;
                while (!s.empty()) {
                    currentMax = max(currentMax, s.top());
                    tempStack.push(s.top());
                    s.pop();
                }
                while (!tempStack.empty()) {
                    s.push(tempStack.top());
                    tempStack.pop();
                }
            } else if (s.empty()) {
                currentMax = LLONG_MIN;
            }
        }
 
        cout << currentMax << '\n';
    }
 
    return 0;
}