#include <bits/stdc++.h>
using namespace std;

string S;

int L;
const int L_MAX = 5001;
const int DIV = 1000000;
int D[L_MAX];

int f(int k) {
    if (D[k] != -1) return D[k];
    
    int res = 0;
    if (S[k-1] == '0') {
        if (S[k-2] == '1' || S[k-2] == '2') res = f(k-2);
    }
    else if (S[k-1] >= '7') {
        res = f(k-1);
        if (S[k-2] == '1') {
            res += f(k-2);
            res %= DIV;
        }
    }
    else {
        res += f(k-1);
        if (S[k-2] == '1' || S[k-2] == '2') {
            res += f(k-2);
            res %= DIV;
        }
    }

    return D[k] = res;
}

int main() {
    cin >> S;
    L = S.size();

    memset(D, -1, sizeof(D));
    D[0] = 1;
    D[1] = (S[0] != '0') ? 1 : 0;

    int res = f(L);
    cout << res << '\n';
    return 0;
}
