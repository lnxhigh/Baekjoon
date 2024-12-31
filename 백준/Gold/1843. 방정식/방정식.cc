#include <bits/stdc++.h>
using namespace std;
using int64 = unsigned long long;
const int MAX = 500005;

bool D[MAX];
bool P[MAX];

int64 A(int64 N) {
    int64 M = N / 2;
    int64 cnt = (M - 1) * M;
    if (N & 1) cnt += M;
    return cnt;
}

int64 B(int64 N) {
    vector<int64> div;

    for (int64 i = 1; i <= N; i++) {
        if (N % i != 0) continue;
        D[i] = true;
        div.push_back(i);
    }
    
    int64 cnt = 0;
    int L = div.size();
    for (int i = 0; i < L; i++) {
        for (int j = i; j < L; j++) {
            int64 X = div[i], Y = div[j];
            int64 Z = X + Y;
            if (Z <= N && D[Z]) cnt++;
        }
    }

    return cnt;
}

int64 C(int64 N) {
    fill(P, P + N, true);
    P[0] = P[1] = false;

    for (int64 i = 0; i <= N; i++) {
        if (!P[i]) continue;
        for (int64 j = i * i; j <= N; j += i) {
            P[j] = false;
        }
    }

    int64 cnt = 0;
    for (int64 i = 5; i <= N; i++) {
        if (P[i] && P[i - 2]) cnt++;
    }

    return cnt;
}

int main() {
    int64 N; cin >> N;
    cout << A(N) << '\n';
    cout << B(N) << '\n';
    cout << C(N) << '\n';
    return 0;
}
