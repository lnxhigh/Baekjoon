#include <bits/stdc++.h>
using namespace std;

int C, N;
pair<int,int> P[20];
const int MAX = 1 << 17;
const int INF = 1 << 24;
int D[MAX];

int main() {
    cin >> C >> N;
    for (int i = 0; i < N; i++) {
        int cost, customer;
        cin >> cost >> customer;
        P[i] = { cost, customer };
    }

    fill(D + 1, D + MAX, INF);

    for (int i = 0; i <= 100000; i++) {
        for (int k = 0; k < N; k++) {
            int cost = P[k].first;
            int customer = P[k].second;
            if (customer > i) continue;
            D[i] = min(D[i], D[i - customer] + cost);
        }
    }

    int res = INF;
    for (int i = C; i <= 100000; i++) {
        res = min(res, D[i]);
    }
    
    cout << res << '\n';
    return 0;
}
