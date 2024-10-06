#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<bool> P;

int sieve(int N, int K) {
    for (int i = 2; i <= N; i++) {
        if (!P[i]) continue;
        if (!--K) return i;
        for (int j = i+i; j <= N; j += i) {
            if (P[j] && !--K) return j;
            P[j] = false;
        }
    }
    return 0;
}

int main() {
    cin >> N >> K;
    P = vector<bool>(N + 1, true);
    cout << sieve(N, K) << '\n';
    return 0;
}
