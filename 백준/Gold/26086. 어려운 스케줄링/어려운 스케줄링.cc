#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N, Q, K;

int main() {
    FastIO
    cin >> N >> Q >> K;

    vector<pair<int,int>> query;
    query.reserve(Q);

    int last = -1;
    for (int i = 0; i < Q; i++) {
        int x = 0, p = 0; cin >> x;
        if (x == 0) cin >> p;
        else if (x == 1) last = i;
        query.push_back({ x, p });
    }

    vector<int> works;
    works.reserve(Q);
    for (int i = 0; i < last; i++) {
        auto [x, p] = query[i];
        if (x == 0) works.push_back(p);
    }
    sort(works.begin(), works.end());
    
    deque<int> dq;
    for (auto p : works) dq.push_back(p);
    bool rev = false;

    for (int i = last + 1; i < Q; i++) {
        auto [x, p] = query[i];
        assert(x != 1);
        if (x == 0) {
            if (!rev) dq.push_front(p);
            else dq.push_back(p);
        }
        else if (x == 2) {
            rev ^= true;
        }
    }

    int ans = 0;
    while (K--) {
        ans = !rev ? dq.front() : dq.back();
        !rev ? dq.pop_front() : dq.pop_back();
    }
    cout << ans << '\n';
    return 0;
}
