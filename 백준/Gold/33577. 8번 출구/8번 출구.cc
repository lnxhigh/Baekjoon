#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const int MAX = 100005;

ll n;
ll arr[MAX];
ll sum[MAX];
ll gain[MAX];
ll max_gain[MAX];

int main() {
    FastIO
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // i번 출구까지 가는데 필요한 면역력의 최솟값

    for (int i = 1; i <= n; i++) {
        sum[i] = arr[i - 1] + sum[i - 1];
    }

    // i번 출구까지 가서 1번 출구로 돌아왔을 때 얻게 되는 면역력

    for (int i = 0; i <= n; i++) {
        gain[i] = arr[i] - sum[i];
        max_gain[i] = i ? max(gain[i], max_gain[i - 1]) : gain[i];
    }

    ll to = 0; // 도달할 수 있는 범위
    ll energy = 0;
    ll ans = 0;

    while (to < n) {
        // 다음 칸으로 이동하는 데 필요한 에너지
        ll need = sum[to + 1] - energy;

        // 1번 출구로 돌아가서 에너지 획득
        ll cnt = need / max_gain[to];
        if (need % max_gain[to] != 0) cnt++;

        energy += cnt * max_gain[to];
        ans += cnt;

        // 도달할 수 있는 곳의 범위 확장
        while (to < n && energy >= sum[to + 1]) to++;
    }

    cout << ans << '\n';

    return 0;
}
