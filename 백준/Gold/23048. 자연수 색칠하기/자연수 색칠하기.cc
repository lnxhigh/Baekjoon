#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N;
const int MAX = 500001;
int color[MAX];

int sieve(int N) {
    memset(color, -1, sizeof(color));

    int cnt = 1;
    color[1] = cnt++;

    for (int i = 2; i <= N; i++) {
        if (color[i] != -1) continue;
        
        for (int j = i; j <= N; j += i) {
            if (color[j] == -1) color[j] = cnt;
        }
        cnt++;
    }

    return --cnt;
}

int main() {
    FastIO
    cin >> N;
    int res = sieve(N);
    cout << res << '\n';
    for (int i = 1; i <= N; i++) {
        cout << color[i] << ' ';
    }
    cout << '\n';
    return 0;
}
