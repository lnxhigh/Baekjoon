#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = unsigned long long;
const int MAX = 100005;

int64 M, N;
int64 A[MAX];

int64 f(int64 x) {
    return x * x;
}

int main() {
    FastIO

    // 입력 처리
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A, A + N);

    // 사탕을 몇 개 빼앗아야 하는가
    int64 X = 0;
    for (int i = 0; i < N; i++) {
        X += A[i];
    }
    X -= M;

    // 사탕 뺏기
    int64 ans = 0;
    int idx = 0;
    int64 cur = 0;

    while (idx < N) {
        int64 cnt = N - idx;
        int64 nxt = A[idx];
        if (X <= cnt * (nxt - cur)) break;

        X -= cnt * (nxt - cur);
        ans += cnt * (f(nxt) - f(cur));
        
        while (A[idx] == nxt) idx++;
        cur = nxt;
    }

    int64 cnt = N - idx;
    int64 nxt = cur + (X / cnt);
    X -= cnt * (nxt - cur);
    ans += cnt * (f(nxt) - f(cur));
    
    cur = nxt, cnt = X, nxt = cur + 1;
    X -= cnt * (nxt - cur);
    ans += cnt * (f(nxt) - f(cur));
    assert(X == 0);

    cout << ans << '\n';
    return 0;
}
