#include <bits/stdc++.h>
using namespace std;

string S;

bool check(string S) {
    int L = S.size();
    for (int i = 0; i < (L >> 1); i++) {
        if (S[i] != S[L-1-i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> S;
    cout << check(S) << '\n';
    return 0;    
}
