#include <bits/stdc++.h>
using namespace std;
const int MAX = 1 << 20;

int n;
int arr[MAX];

int solve(int k) {
    deque<tuple<int,int,int>> dq;
    dq.push_back({ 0, 0, arr[0] });

    for (int i = 1; i < n; i++) {
        while (!dq.empty()) {
            auto [idx, cnt, num] = dq.front();
            if (idx < i - k) dq.pop_front();
            else break;
        }

        auto [idx, cnt, num] = dq.front();
        int nidx = i, ncnt = (arr[i] >= num) ? cnt + 1 : cnt, nnum = arr[i];

        while (!dq.empty()) {
            auto [idx, cnt, num] = dq.back();
            if ((cnt > ncnt) || (cnt == ncnt && num <= nnum)) dq.pop_back();
            else break;
        }

        dq.push_back({ nidx, ncnt, nnum });
    }

    auto [idx, cnt, num] = dq.back();
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int q; cin >> q;
    while (q--) {
        int k; cin >> k;
        cout << solve(k) << '\n';
    }
    
    return 0;
}
