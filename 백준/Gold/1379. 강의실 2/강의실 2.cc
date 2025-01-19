#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100005;

int N;
tuple<int,int,int> A[MAX];
int D[MAX];

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        int idx, s, e; cin >> idx >> s >> e;
        A[i] = { s, e, --idx };
    }
    sort(A, A + N);

    int cnt = 0;
    priority_queue<pair<int,int>> pq;
    
    set<int> available;
    for (int i = 1; i <= N; i++) available.insert(i);

    for (int i = 0; i < N; i++) {
        const auto& [s, e, idx] = A[i];

        while (!pq.empty() && -pq.top().first <= s) {
            available.insert(D[pq.top().second]);
            pq.pop();
        }
        
        auto iter = available.begin();
        D[idx] = *iter;
        available.erase(iter);
        pq.push({ -e, idx });

        cnt = max(cnt, (int) pq.size());
    }

    cout << cnt << '\n';
    for (int i = 0; i < N; i++) {
        cout << D[i] << '\n';
    }

    return 0;
}
