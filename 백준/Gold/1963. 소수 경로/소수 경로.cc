#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int MAX = 10000;
bool isPrime[MAX];
bool visited[MAX];

void init() {
    fill(isPrime, isPrime + MAX, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 0; i < MAX; i++) {
        if (!isPrime[i]) continue;
        for (int j = i+i; j < MAX; j += i) {
            isPrime[j] = false;
        }
    }
}

vector<int> generate(int X) {
    vector<int> res;
    if (X < 1000) return res;
    
    int K = X;
    int mul = 1;
    while (K) {
        int d = K % 10;
        int Y = X - d * mul;
        for (int i = 0; i < 10; i++) {
            if (i == d || (i == 0 && mul == 1000)) continue;
            res.push_back(Y + i * mul);
        }
        
        K /= 10;
        mul *= 10;
    }

    return res;
}

int solve(int S, int T) {
    memset(visited, 0, sizeof(visited));
    queue<pair<int,int>> q;
    q.push({ S, 0 });
    visited[S] = true;

    while (!q.empty()) {
        int X = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (X == T) return depth;

        vector<int> next = generate(X);
        for (int Y : next) {
            if (visited[Y] || !isPrime[Y] || Y < 1000) continue;
            q.push({ Y, depth+1 });
        }
    }

    return -1;
}

int main() {
    FastIO
    int TC; cin >> TC;

    init();

    while (TC--) {
        int S, T; cin >> S >> T;
        int res = solve(S, T);
        if (res >= 0) cout << res;
        else cout << "Impossible";
        cout << '\n';
    }
    return 0;
}
