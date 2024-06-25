#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
ll Die[6], V[7];

enum { A, B, C, D, E, F };
vector<int> adj[6] = {
    { B, D, E, C },
    { F, D, A, C },
    { B, A, E, F },
    { B, F, E, A },
    { A, D, F, C },
    { E, D, B, C }
};

void init() {
    ll sum = 0;

    fill(V, V + 7, 1LL << 30);
    for (int i = 0; i < 6; i++) {
        V[1] = min(V[1], Die[i]);
        sum += Die[i];
    }
    for (int i = 0; i < 6; i++) {    
        for (int k = 0; k < 4; k++) {
            V[2] = min(V[2], Die[i] + Die[adj[i][k]]);
            V[3] = min(V[3], Die[i] + Die[adj[i][k]] + Die[adj[i][(k+1) % 4]]);
        }
    }
    
    for (int i = 0; i < 6; i++) {
        V[5] = min(V[5], sum - Die[i]);
    }
}

ll solve(int N) {
    if (N == 1) return V[5];

    ll res = 0;
    res += V[1] * (N-2) * (N-2); // 윗면
    res += V[1] * 4 * (N-1) * (N-2); // 옆면
    res += V[2] * (N-2) * 4; // 윗면
    res += V[2] * (N-1) * 4; // 옆면
    res += V[3] * 4; // 윗면

    return res;
}

int main() {
    cin >> N;
    for (int i = 0; i < 6; i++) cin >> Die[i];
    
    init();
    ll res = solve(N);
    cout << res << '\n';
    
    return 0;
}
