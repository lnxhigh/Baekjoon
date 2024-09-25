#include <bits/stdc++.h>
using namespace std;

int F[32];

pair<int,int> solve(int D, int K) {
    for (int i = 1; i <= K; i++) {
        int j = K - F[D-2] * i;
        if (j % F[D-1] != 0) continue;
        
        int x = i, y = j / F[D-1];
        return { x, y };
    }

    return { -1, -1 };
}

int main() {
    int D, K; cin >> D >> K;

    F[0] = 0, F[1] = 1;
    for (int i = 2; i < 32; i++) {
        F[i] = F[i-1] + F[i-2];
    }

    pair<int,int> p = solve(D, K);
    int A = p.first, B = p.second;
    cout << A << '\n' << B << '\n';
    return 0;
}
