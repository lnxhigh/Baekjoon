#include <bits/stdc++.h>
using namespace std;

int N;

int solve(int N) {
    queue<int> q;
    for (int i = 1; i <= N; i++) q.push(i);
    
    while (q.size() > 1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    return q.front();
}

int main() {
    cin >> N;
    int res = solve(N);
    cout << res << '\n';
    return 0;
}
