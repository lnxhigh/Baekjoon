#include <bits/stdc++.h>
using namespace std;

string S;
int X, K, L;

int main() {
    cin >> S;
    L = S.size();
    for (int i = 0; i < L; i++) {
        if (S[i] == '(') { K++; }
        else { K--; X += (S[i-1] == '(') ? K : 1; }
    }
    cout << X << '\n';
    return 0;
}
