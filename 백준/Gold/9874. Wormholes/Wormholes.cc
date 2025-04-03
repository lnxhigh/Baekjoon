#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 4;

int N;
pair<int,int> Data[MAX];

vector<int> D;
int ans = 0;

int in(int x) { return x * 2; }
int out(int x) { return x * 2 + 1; }

int main() {
    FastIO
    cin >> N;
    D = vector<int>(N * 2, -1);

    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        Data[i] = { x, y };
    }

    for (int i = 0; i < N; i++) {
        int inIdx = -1;
        auto [x, y] = Data[i];

        for (int j = 0; j < N; j++) {
            auto [nx, ny] = Data[j];
            if (ny != y || nx <= x) continue;
            if (inIdx == -1 || nx < Data[inIdx].first) inIdx = j;
        }

        // out -> in
        if (inIdx != -1) D[out(i)] = in(inIdx);
    }

    for (int bits = 0; bits < (1 << N); bits++) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (bits >> i & 1) cnt++;
        }
        if (cnt != N / 2) continue;

        vector<int> one, other;
        for (int i = 0; i < N; i++) {
            if (bits >> i & 1) one.push_back(i);
            else other.push_back(i);
        }

        do {
            vector<int> P = D;
            for (int i = 0; i < N / 2; i++) {
                int x = one[i], y = other[i];
                P[in(x)] = out(y), P[in(y)] = out(x);
            }
            
            queue<int> q;
            vector<int> deg(N * 2);
            bool stuck = false;

            for (int i = 0; i < N * 2; i++) {
                if (P[i] >= 0) deg[P[i]]++;
            }

            for (int i = 0; i < N * 2; i++) {
                if (deg[i] == 0) q.push(i);
            }

            for (int i = 0; i < N * 2; i++) {
                if (q.empty()) {
                    stuck = true;
                    break;
                }

                int x = q.front();
                q.pop();

                int nxt = P[x];
                if (nxt < 0) continue;
                else if (--deg[nxt] == 0) q.push(nxt);
            }

            if (stuck) ans++;

        } while (next_permutation(other.begin(), other.end()));
    }

    ans /= (1 << (N / 2));
    cout << ans << '\n';

    return 0;
}
