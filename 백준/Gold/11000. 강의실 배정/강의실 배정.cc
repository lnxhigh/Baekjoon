#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 1 << 18;
pair<int,int> C[MAX];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++) {
        int S, E;
        cin >> S >> E;
        C[i] = { S, E };
    }
    
    sort(C, C + N);

    int X = 0;
    for (int i = 0; i < N; i++) {
        int S = C[i].first, E = C[i].second;
        while (!pq.empty() && pq.top() <= S) pq.pop();
        pq.push(E);
        X = max(X, (int) pq.size());
    }

    cout << X << '\n';
    return 0;
}
