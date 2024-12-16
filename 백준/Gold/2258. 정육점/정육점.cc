#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100000;

int N, M;
pair<int,int> Meat[MAX];
map<int,int> P;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int weight, price; cin >> weight >> price;
        Meat[i] = { price, -weight };
    }
    sort(Meat, Meat + N);
}

int solve() {
    int ret = INT_MAX;
    bool flag = false;
    int sum = 0;

    for (int i = 0; i < N; i++) {
        auto [price, weight] = Meat[i];
        weight = -weight;

        int cnt = ++P[price];
        sum += weight;

        if (sum >= M) {
            ret = min(ret, cnt * price);
            flag = true;
        }
    }

    return flag ? ret : -1;
}

int main() {
    FastIO
    input();
    int ans = solve();
    cout << ans << '\n';
    return 0;
}
