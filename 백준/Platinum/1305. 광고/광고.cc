#include <bits/stdc++.h>
using namespace std;

int L;
string S;
int F[1000000];

int main() {
    cin >> L >> S;
    for (int i = 1, k = 0; i < L; i++) {
        while (k > 0 && S[i] != S[k]) k = F[k-1];
        if (S[i] == S[k]) F[i] = ++k;
    }
    cout << L - F[L-1] << '\n';
    return 0;
}
