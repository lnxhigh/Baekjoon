#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 20;

int N;
int L, P;

vector<int> D[MAX];
priority_queue<int> pq;

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        int X, F; cin >> X >> F;
        D[X].push_back(F);
    }
    cin >> L >> P;

    int cnt = 0;
    bool reach = true;

    for (int i = 0; i < L; i++) {
        for (int F : D[i]) {
            pq.push(F);
        }

        if (P == 0) {
            if (pq.empty()) {
                reach = false;
                break;
            }
            else {
                cnt++;
                P += pq.top();
                pq.pop();
            }
        }

        P--;
    }

    int ans = reach ? cnt : -1;
    cout << ans << '\n';
    return 0;
}
