#include <bits/stdc++.h>
using namespace std;

const int N = 12;
vector<int> graph[N];

int solve() {
    for (int i = 0; i < N; i++) {
        if ((int) graph[i].size() != 3) continue;

        int cnt = 0;
        for (int k : graph[i]) cnt += graph[k].size();
        if (cnt == 6) return i;
    }

    return -1;
}

int main() {
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        --X; --Y;
        graph[X].push_back(Y);
        graph[Y].push_back(X);
    }

    int spica = solve();
    cout << ++spica << '\n';
    return 0;
}
