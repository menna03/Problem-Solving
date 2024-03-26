#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
bool isValidPalindrome(const string& substring, const unordered_set<char>& validChars) {
    for (char ch : substring) {
        if (validChars.find(ch) == validChars.end()) {
            return false;
        }
    }
    return substring == string(substring.rbegin(), substring.rend());
}
 
int maxPalindromeSubstringSize(int n, const string& s, int m, const unordered_set<char>& validChars) {
    int maxLength = -1;
 
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            string substring = s.substr(i, j - i);
            if (isValidPalindrome(substring, validChars)) {
                maxLength = max(maxLength, static_cast<int>(substring.length()));
            }
        }
    }
 
    return maxLength;
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n;
    string s;
    cin >> s;
    cin >> m;
 
    unordered_set<char> validChars;
    for (int i = 0; i < m; ++i) {
        char ch;
        cin >> ch;
        validChars.insert(ch);
    }
 
    int result = maxPalindromeSubstringSize(n, s, m, validChars);
    cout << result << endl;
 
    return 0;
}