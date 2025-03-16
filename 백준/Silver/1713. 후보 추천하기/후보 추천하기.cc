#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N, K;
int frame[21];
bool posted[101];
int vote[101], postTime[101];

int main() {
    FastIO
    cin >> N >> K;

    // 2 1 4 3 5 6 2 7 2
    // 프레임 3개
    // 

    for (int t = 1; t <= K; t++) {
        int x; cin >> x;

        if (posted[x]) { vote[x]++; continue; }
        posted[x] = true;

        int idx = 1;
        while (idx <= N) {
            if (frame[idx] == 0) break;
            else idx++;
        }

        if (idx <= N) {
            frame[idx] = x;
            vote[x]++;
            postTime[x] = t;
            continue;
        }

        int del = 0;
        int val = 1 << 20;

        for (int i = 1; i <= N; i++) {
            int cur = frame[i];
            if (vote[cur] < val) val = vote[cur], del = i;
            else if (vote[cur] == val && postTime[cur] < postTime[frame[del]]) del = i;
        }

        int prv = frame[del];
        posted[prv] = false;
        vote[prv] = 0;
        postTime[prv] = 0;

        frame[del] = x;
        vote[x]++;
        postTime[x] = t;
    }

    vector<int> res;
    for (int i = 1; i <= N; i++) {
        if (frame[i]) res.push_back(frame[i]);
    }
    sort(res.begin(), res.end());

    for (int x : res) cout << x << ' ';
    cout << '\n';
    return 0;
}
