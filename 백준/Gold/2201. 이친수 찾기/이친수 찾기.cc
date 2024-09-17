#include <bits/stdc++.h>
using namespace std;

long long N, K = 0;
long long F[100] = { 0, 1 };

int main() {
    cin >> K;
    for (int i = 2; i <= 100; i++) {
        F[i] = F[i-1] + F[i-2];
        if (F[i] > K) { N = i - 1; break; }
    }

    string pinary;
    for (int i = N; i > 1; i--) {
        char x = (K >= F[i]) ? '1' : '0';
        if (K >= F[i]) K -= F[i];
        pinary.push_back(x);
    }

    cout << pinary << '\n';
    return 0;
}
