#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define For(i, n) for (int i = 0; i < n; i++)
using namespace std;

int N, M;
const int MAX = 1 << 6;
int Box[MAX][MAX];
bool shouldMove[MAX];
int color[MAX];

int main() {
    FastIO
    cin >> N >> M;
    For(i, N) {
        For(j, M) {
            cin >> Box[i][j];
        }
    }

    fill(color, color + N, -1);
    For(i, N) {
        For(j, M) {
            if (Box[i][j] > 0) color[i] = j;
        }
    }

    For(i, N) {
        int cnt = 0;
        For(j, M) {
            if (Box[i][j] == 0) continue;
            color[i] = j;
            cnt++;
        }

        if (cnt > 1) shouldMove[i] = true;
        if (shouldMove[i]) continue;

        for (int k = 0; k < i; k++) {
            if (shouldMove[k]) continue;
            if (color[k] != -1 && color[k] == color[i]) {
                shouldMove[i] = true;
            }
        }
    }
    
    int res = 0;
    for (int i = 0; i < N; i++) {
        if (shouldMove[i]) res++;
    }
    
    if (res != 0) res--;
    cout << res << '\n';
    return 0;
}
