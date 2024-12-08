#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    priority_queue<int> pq;

    int cnt = 0;
    int vote; cin >> vote;
    for (int i = 1; i < N; i++) {
        int x; cin >> x;
        pq.push(x);
    }

    while (!pq.empty()) {
        int x = pq.top();
        pq.pop();
        
        if (vote + cnt > x) break;
        cnt++;

        if (--x) pq.push(x);
    }

    cout << cnt << '\n';
    return 0;
}
