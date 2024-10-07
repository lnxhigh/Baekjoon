#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

// 정수 i (0 <= i < N) 에 대해
// N 을 X 로 나눈 나머지가 Y 미만인 수의 개수
int64 __f(int64 N, int64 X, int64 Y) {
    int64 Q = N / X, R = N % X;
    return Q * Y + min(R, Y);
}

// A 이상 B 미만의 수에 대해
// X 로 나눈 나머지가 P 이상 Q 미만인 수의 개수
int64 f(int64 A, int64 B, int64 X, int64 P, int64 Q) {
    if (A >= B || P >= Q) return 0;
    return (__f(B, X, Q) - __f(A, X, Q)) - (__f(B, X, P) - __f(A, X, P));
}

// ex) 십의 자리가 k인 수의 개수는
// 십 이상 N+1 미만의 수에 대해 백으로 나눴을 때 나머지가 십*k 이상 십*(k+1) 미만인 수의 개수
vector<int64> solve(int64 N) {
    vector<int64> cnt(10);
    for (int64 i = 1; i <= N; i *= 10) {
        for (int d = 0; d < 10; d++) {
            cnt[d] += f(i, N + 1, i * 10, i * d, i * (d + 1));
        }
    }
    return cnt;
}

int main() {
    int64 N; cin >> N;
    auto V = solve(N);
    for (int64 x : V) cout << x << ' ';
    cout << '\n';
    return 0;
}
