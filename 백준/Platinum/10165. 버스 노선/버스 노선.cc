#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 500'001;

int N, M;
bool D[MAX];

int main() {
    FastIO
    cin >> N >> M;

    vector<tuple<int,int,int>> Data;
    Data.reserve(M << 1);

    for (int idx = 0; idx < M; idx++) {
        int x, y; cin >> x >> y;
        if (x > y) y += N;
        
        int len = y - x;

        Data.push_back({ x, -len, idx });
        if (y < N) Data.push_back({ x + N, -len, idx });
    }

    sort(Data.begin(), Data.end());

    priority_queue<int> pq;

    for (auto [x, len, idx] : Data) {
        len = -len;
        if (!pq.empty() && x + len <= pq.top()) D[idx] = true;
        if (!D[idx]) pq.push(x + len);
    }

    for (int i = 0; i < M; i++) {
        if (!D[i]) cout << i + 1 << ' ';
    }
    cout << '\n';

    return 0;
}
