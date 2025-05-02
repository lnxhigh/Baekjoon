#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 200'001;

int n;
int arr[MAX];
int height[MAX];

pair<int,int> tree[MAX];
set<int> nodes[MAX];
map<int,int> idx;

bool solve() {
    if (nodes[1].size() != 1u) {
        return false;
    }

    // height, idx, min, max
    queue<tuple<int,int,int,int>> q;

    // Init
    {
        auto iter = nodes[1].begin();
        q.push({ 1, idx[*iter], INT_MIN, INT_MAX });
        nodes[1].erase(*iter);
    }

    while (!q.empty()) {
        auto [h, cur, mn, mx] = q.front();
        int val = arr[cur];
        q.pop();
        
        // Left
        {   
            auto iter = nodes[h + 1].upper_bound(mn);

            if (iter != nodes[h + 1].end() && (*iter < val)) {
                int nxt = idx[*iter];
                tree[cur].first = nxt;

                q.push({ h + 1, nxt, mn, val });
                nodes[h + 1].erase(*iter);
            }
        }

        // Right
        {   
            auto iter = nodes[h + 1].upper_bound(val);

            if (iter != nodes[h + 1].end() && (*iter < mx)) {
                int nxt = idx[*iter];
                tree[cur].second = nxt;

                q.push({ h + 1, nxt, val, mx });
                nodes[h + 1].erase(*iter);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (!nodes[i].empty()) {
            return false;
        }
    }

    return true;
}

int main() {
    FastIO

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i] >> height[i];
        tree[i] = { -1, -1 };
        nodes[height[i]].insert(arr[i]);
        idx[arr[i]] = i;
    }

    bool flag = solve();

    if (flag) {
        for (int i = 1; i <= n; i++) {
            cout << tree[i].first << ' ' << tree[i].second << '\n';
        }
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}
