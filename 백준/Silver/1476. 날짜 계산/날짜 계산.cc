#include <bits/stdc++.h>
using namespace std;

tuple<int,int,int> euclidean(int a, int b) {
    if (b == 0) return { a, 1, 0 };
    auto [ g, x, y ] = euclidean(b, a % b);
    return { g, y, x - (a / b) * y };
}

int main() {
    int E, S, M; cin >> E >> S >> M;
    --E, --S, --M;

    // CRT: K % X[i] = R[i] for i = 0, 1, 2
    int X[3] = { 15, 28, 19 };
    int R[3] = { E, S, M };
    int P = 15 * 28 * 19;

    int K = 0;
    for (int i = 0; i < 3; i++) {
        int Mi = P / X[i];
        auto [g, Yi, _] = euclidean(Mi, X[i]);
        K += Mi * Yi * R[i];
    }

    K = (K % P + P) % P;
    cout << ++K << '\n';
    return 0;
}
