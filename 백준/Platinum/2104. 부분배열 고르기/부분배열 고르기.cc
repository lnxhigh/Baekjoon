#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const int MAX = 100'005;

ll n;
ll arr[MAX];
vector<int> nums[1 << 20];

bool on[MAX];
int par[MAX];
ll sum[MAX], mn[MAX];

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    else if (x < y) swap(x, y);

    par[x] = y;
    sum[y] += sum[x];
    mn[y] = min(mn[y], mn[x]);

    return true;
}

int main() {
    FastIO
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        nums[arr[i]].push_back(i);
        par[i] = i;
    }

    long long ans = 0;

    for (int x = 1'000'000; x >= 0; x--) {
        for (int i : nums[x]) {
            on[i] = true;
            sum[i] = mn[i] = x;

            if (on[i + 1]) merge(i, i + 1);
            if (on[i - 1]) merge(i - 1, i);

            int p = find(i);
            ans = max(ans, sum[p] * mn[p]);
        }
    }
    
    cout << ans << '\n';

    return 0;
}
