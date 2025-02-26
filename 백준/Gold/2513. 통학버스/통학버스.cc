#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100000;

int N, K, S;
int A[MAX + 1];

int main() {
    FastIO
    cin >> N >> K >> S;

    for (int i = 0; i < N; i++) {
        int x, cnt; cin >> x >> cnt;
        A[x] += cnt;
    }

    int ans = 0;
    int cnt = 0;
    int t = 0;

    int i = 0;

    while (i < S) {
        if (A[i] == 0) {
            i++;
            continue;
        }

        if (cnt == K) {
            ans += t;
            cnt = 0;
            t = 0;
        }

        if (cnt == 0) {
            t = abs(S - i) * 2;
            ans += (A[i] / K) * t;
            cnt += A[i] % K;
            A[i] = 0;
        }
        else {
            int add = min(K - cnt, A[i]);
            cnt += add;
            A[i] -= add;
        }
    }

    if (cnt) {
        ans += t;
        cnt = 0;
        t = 0;
    }

    i = MAX;
    
    while (i > S) {
        if (A[i] == 0) {
            i--;
            continue;
        }

        if (cnt == K) {
            ans += t;
            cnt = 0;
            t = 0;
        }

        if (cnt == 0) {
            t = abs(S - i) * 2;
            ans += (A[i] / K) * t;
            cnt += A[i] % K;
            A[i] = 0;
        }
        else {  
            int add = min(K - cnt, A[i]);
            cnt += add;
            A[i] -= add;
        }
    }

    if (cnt) {
        ans += t;
        cnt = 0;
        t = 0;
    }

    cout << ans << '\n';
    return 0;
}
