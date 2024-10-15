#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    int64 N, M; cin >> N >> M;
    
    int64 S = N;
    for (int64 i = 0; i < N; i++) { int64 X; cin >> X; S += X; }

    ++N;    
    M = max(M - S, 0LL);
    int64 Q = M / N, R = M % N;
    int64 X = N * Q * (Q + 1) * (2 * Q + 1) / 6;
    int64 Y = R * (Q + 1) * (Q + 1);

    cout << X + Y << '\n';
    return 0;
}
