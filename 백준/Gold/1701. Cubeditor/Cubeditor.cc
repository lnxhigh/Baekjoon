#include <bits/stdc++.h>
using namespace std;

int f(const string &S) {
    int X = 0;
    int L = S.size();
    vector<int> F(L, 0);

    for (int i = 1, k = 0; i < L; i++) {
        while (k > 0 && S[i] != S[k]) k = F[k-1];
        if (S[i] == S[k]) F[i] = ++k;
        X = max(X, F[i]);
    }

    return X;
}

int main() {
    string S;
    cin >> S;

    int X = 0;
    for (int i = 0; i < (int) S.size(); i++) {
        string T = S.substr(i);
        X = max(X, f(T));
    }

    cout << X << '\n';
    return 0;
}
