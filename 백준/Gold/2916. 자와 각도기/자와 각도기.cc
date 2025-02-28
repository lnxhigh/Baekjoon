#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N, K;
int A[10];
bool D[360];

int main() {
    FastIO
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    queue<int> q;
    q.push(0);
    D[0] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < N; i++) {
            int nxt = x + A[i];
            if (nxt >= 360) nxt -= 360;
            if (!D[nxt]) q.push(nxt), D[nxt] = true;
        }

        for (int i = 0; i < N; i++) {
            int nxt = x - A[i];
            if (nxt < 0) nxt += 360;
            if (!D[nxt]) q.push(nxt), D[nxt] = true;
        }
    }

    while (K--) {
        int x; cin >> x;
        string ans = D[x] ? "YES" : "NO";
        cout << ans << '\n';
    }

    return 0;
}
