#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100000;

int N, X;
pair<int,int> A[MAX];
priority_queue<pair<int,int>> pq;
int D[MAX];
set<int> Available;

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        int s, e; cin >> s >> e;
        A[i] = { s, e };
    }
    sort(A, A + N);

    for (int i = 0; i < N; i++) {
        Available.insert(i);
    }

    for (int i = 0; i < N; i++) {
        auto [s, e] = A[i];
        while (!pq.empty()) {
            auto [t, k] = pq.top();
            if (-t > s) break;
            
            pq.pop();
            Available.insert(k);
        }

        auto iter = Available.begin();
        int k = *iter;
        
        Available.erase(iter);
        D[k]++;
        pq.push({ -e, k });
        X = max(X, (int) pq.size());
    }

    cout << X << '\n';
    for (int i = 0; i < X; i++) {
        cout << D[i] << ' ';
    }
    cout << '\n';

    return 0;
}
