#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 10001;

int N;
string S[MAX];

bool compare(const string &X, const string &Y) {
    size_t i = 0, j = 0;

    while (i < X.size() && j < Y.size()) {
        if (isdigit(X[i]) && isdigit(Y[j])) {
            size_t zi = 0, zj = 0;
            size_t nxti = i, nxtj = j;

            while (nxti < X.size() && X[nxti] == '0') zi++, nxti++;
            while (nxti < X.size() && isdigit(X[nxti])) nxti++;

            while (nxtj < Y.size() && Y[nxtj] == '0') zj++, nxtj++;
            while (nxtj < Y.size() && isdigit(Y[nxtj])) nxtj++;

            i += zi, j += zj;

            if (nxti - i != nxtj - j) return nxti - i < nxtj - j;

            size_t len = nxti - i;
            for (size_t k = 0; k < len; k++) {
                if (X[i + k] != Y[j + k]) return X[i + k] < Y[j + k];
            }

            if (zi != zj) return zi < zj;

            i = nxti, j = nxtj;
        }
        else if (!isdigit(X[i]) && !isdigit(Y[j])) {
            if (X[i] == Y[j]) {
                i++, j++;
                continue;
            }
            else if (tolower(X[i]) != tolower(Y[j])) {
                return tolower(X[i]) < tolower(Y[j]);
            }
            else {
                return X[i] < Y[j];
            }
        }
        else {
            return isdigit(X[i]);
        }
    }

    return X.size() < Y.size();
}

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    sort(S, S + N, compare);
    for (int i = 0; i < N; i++) {
        cout << S[i] << '\n';
    }

    return 0;
}
