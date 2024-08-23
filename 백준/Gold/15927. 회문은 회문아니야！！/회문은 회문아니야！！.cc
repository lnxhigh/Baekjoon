#include <bits/stdc++.h>
using namespace std;

string S;

int solve(const string &S) {
    int L = S.size();
    bool isPalindrome = true;

    for (int i = 0; i < L / 2; i++) {
        if (S[i] != S[L-1-i]) {
            isPalindrome = false;
            break;
        }
    }

    if (!isPalindrome) return L;
    
    bool same = true;
    char first = S[0];
    for (const char &c : S) {
        if (c != first) {
            same = false;
            break;
        }
    }

    if (same) return -1;
    return L - 1;
}

int main() {
    cin >> S;
    int res = solve(S);
    cout << res << '\n';
    return 0;
}
