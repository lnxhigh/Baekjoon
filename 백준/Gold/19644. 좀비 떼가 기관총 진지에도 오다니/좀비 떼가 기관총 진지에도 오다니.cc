#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 3000005;

int L, ML, MK, C;
int Z[MAX], D[MAX];

void input() {
    cin >> L;
    cin >> ML >> MK;
    cin >> C;
    for (int i = 1; i <= L; i++) {
        cin >> Z[i];
    }
}

bool solve() {
    int cnt = 0;

    for (int t = 1; t <= L; t++) {
        int health = Z[t];
        int ammo = D[t - 1] - D[max(t - ML, 0)]; // 유효 사거리 내에서 수류탄 사용 횟수
        int shoot = min(t, ML) - ammo; // 기관총 사용 횟수
        int damage = max(shoot * MK, 0);

        if (health > damage) cnt++; // 기관총으로 제압할 수 없으면 수류탄 사용
        D[t] = cnt;
    }

    return D[L] <= C;
}

int main() {
    FastIO
    input();
    bool flag = solve();
    string ans = flag ? "YES" : "NO";
    cout << ans << '\n';
    return 0;
}
