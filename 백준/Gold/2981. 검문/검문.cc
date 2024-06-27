#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 100;
int A[N_MAX];
int D[N_MAX * N_MAX];
set<int> S;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void divisor(int K, set<int> &S) {
    int M = floor(sqrt(K));
    for (int div = 1; div <= M; div++) {
        if (K % div == 0) {
            S.insert(div);
            S.insert(K / div);
        }
    }
    S.erase(1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    int L = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            D[L++] = abs(A[i] - A[j]);
        }
    }

    int K = D[0];
    for (int i = 0; i < L; i++) {
        K = gcd(K, D[i]);
    }

    divisor(K, S);
    for (int i : S) cout << i << ' ';
    cout << '\n';
    return 0;
}
