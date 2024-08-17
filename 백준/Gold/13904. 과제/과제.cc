#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 1 << 10;
pair<int,int> works[MAX];
priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int d, w;
        cin >> d >> w;
        works[i] = { d, w };
    }

    sort(works, works + N);

    int res = 0;
    int D = works[N-1].first;
    int from = N-1;

    for (int day = D; day > 0; day--) {
        for (int i = from; i >= 0; i--) {
            int d = works[i].first;
            int w = works[i].second;

            if (d == day) pq.push(w);
            else { from = i; break; }
        }

        if (pq.empty()) continue;

        res += pq.top();
        pq.pop();
    }

    cout << res << '\n';
    return 0;
}
