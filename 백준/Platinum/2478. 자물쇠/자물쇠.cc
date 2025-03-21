#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int N;
int A[MAX], B[MAX];

tuple<int,int,int,int> solve() {
    for (int x = 1; x < N; x++) {
        for (int y = N - 1; y > 0; y--) {
            int p = 0, q = N - 1;

            int cnt = 0;
            while (cnt < N && A[x + p] == B[y + p]) p++, cnt++;
            while (cnt > 0 && A[x + q] == B[y + q]) q--, cnt--;
            if (p >= q) continue;

            int np = p, nq = q;
            bool valid = true;

            while (np <= nq) {
                if (A[x + np] != B[y + nq] || A[x + nq] != B[y + np]) valid = false;
                if (!valid) break;
                np++, nq--;
            }

            if (valid) return { x, N - y, p + 1, q + 1 };
        }
    }

    return { 0, 0, 0, 0 };
}

int main() {
    FastIO
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        A[i] = i + 1;
        A[i + N] = A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        B[i + N] = B[i];
    }

    auto [x, y, p, q] = solve();
    cout << x << '\n';
    cout << p << ' ' << q << '\n';
    cout << y << '\n';
    
    return 0;
}
