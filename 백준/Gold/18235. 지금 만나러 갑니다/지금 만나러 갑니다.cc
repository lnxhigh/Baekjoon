#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int INF = 1 << 20;
const int MAX = 20;

int N, A, B;
unordered_set<int> D[MAX];

int main() {
    FastIO
    cin >> N >> A >> B;
    for (int i = 0; i < (1 << MAX); i++) {
        int X = A;

        for (int day = 0; day < MAX; day++) {
            int sign = (i >> day & 1) ? +1 : -1;
            int jump = 1 << day;
            X += sign * jump;
            if (X <= 0 || X > N) break;
            
            D[day].insert(X);
        }
    }

    int ans = INF;

    for (int i = 0; i < (1 << MAX); i++) {
        int X = B;

        for (int day = 0; day < MAX; day++) {
            int sign = (i >> day & 1) ? +1 : -1;
            int jump = 1 << day;

            X += sign * jump;
            if (X <= 0 || X > N) break;
            else if (D[day].find(X) != D[day].end()) { ans = min(ans, day + 1); break; }
        }
    }

    if (ans >= INF) ans = -1;
    cout << ans << '\n';
    return 0;
}
