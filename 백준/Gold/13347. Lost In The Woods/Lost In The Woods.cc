#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 20;

int N, E;
vector<int> graph[MAX];

int main() {
    FastIO
    cin >> N >> E;

    int cnt = 0;
    for (int i = 0; i < E; i++) {
        int X, Y; cin >> X >> Y;
        graph[X].push_back(Y);
        graph[Y].push_back(X);
    }
    
    vector<double> D(N);
    D[0] = 1;

    double ans = 0;
    int iter = 100000;

    for (int k = 1; k < iter; k++) {
        for (int x : graph[N - 1]) {
            ans += k * D[x] / graph[x].size();
        }

        vector<double> T(N);
        for (int i = 0; i < N - 1; i++) {
            for (int x : graph[i]) {
                T[x] += D[i] / graph[i].size();
            }
        }

        for (int i = 0; i < N; i++) {
            D[i] = T[i];
        }
    }

    cout << setprecision(16);
    cout << ans << '\n';
    return 0;
}
