#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int TC;

// Hypothesis
// The number of 'a' is not less than the number of 'b'

bool isGood(const string &S) {
    int size = 0;
    for (char c : S) {
        if (c == 'a') {
            size++;
        }
        else {
            if (size == 0) return false;
            size--;
        }
    }

    return size == 0;
}

int solve(const string &S, const string &T) {
    if (S.size() != T.size()) return -1;
    if (!isGood(S) || !isGood(T)) return -1;
    
    int L = S.size();
    vector<int> A, B;
    A.reserve(L / 2); B.reserve(L / 2);
    
    for (int i = 0; i < (int) S.size(); i++) {
        if (S[i] == 'a') A.push_back(i);
        if (T[i] == 'a') B.push_back(i);
    }

    int res = 0;
    for (int i = 0; i < L / 2; i++) {
        int diff = abs(A[i] - B[i]);
        res += diff;
    }

    return res;
}

int main() {
    FastIO
    cin >> TC;
    while (TC--) {
        string S, T;
        cin >> S >> T;
        cout << solve(S, T) << '\n';
    }
    return 0;
}
