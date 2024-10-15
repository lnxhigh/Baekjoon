#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    
    int S = N;
    for (int i = 0; i < N; i++) { int X; cin >> X; S += X; }
    N++, M = max(M - S, 0);
    
    int Q = M / N, R = M % N;
    int X = N * Q * (Q + 1) * (2 * Q + 1) / 6;
    int Y = R * (Q + 1) * (Q + 1);

    cout << X + Y << '\n';
    return 0;
}
