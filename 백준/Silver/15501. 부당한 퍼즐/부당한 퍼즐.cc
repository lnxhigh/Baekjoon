#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int N;
vector<int> S, T;

bool solve(const vector<int> &S, const vector<int> &T) {
    queue<int> q;
    for (const int &k : S) { q.push(k); }

    int start = *T.begin();
    while (q.front() != start) {
        int front = q.front();
        q.pop();
        q.push(front);
    }

    for (int i = 0; i < N; i++) {
        int cur = q.front();
        q.pop();
        if (cur != T[i]) return false;
    }

    return true;
}

int main() {
    FastIO

    cin >> N;
    S.reserve(N);
    T.reserve(N);
    
    for (int i = 0; i < N; i++) { int X; cin >> X; S.push_back(X); }
    for (int i = 0; i < N; i++) { int X; cin >> X; T.push_back(X); }

    bool x = solve(S, T);
    
    reverse(S.begin(), S.end());
    bool y = solve(S, T);

    string res = (x || y) ? "good" : "bad";

    cout << res << " puzzle" << '\n';
    return 0;
}
