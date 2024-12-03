#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int MAX = 100000;

int64 N, M;
int64 A[MAX];
int64 S[MAX];

bool f(int64 x) {
    if (x == 0) return true;
    
    int64 remain = M - x;
    int64 cnt = remain / x;
    if (cnt == 0) return false;

    int64 all = S[N - 1];
    int64 votes = all - S[cnt - 1];
    return all >= votes * 2;
}

int main() {
    FastIO
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];

    auto compare = [] (int64 &x, int64 &y) { return x > y; };
    sort(A, A + N, compare);
    
    S[0] = A[0];
    for (int i = 1; i < N; i++) S[i] = S[i - 1] + A[i];

    int64 ans = 0;
    int64 low = 0, high = M;
    while (low <= high) {
        int64 mid = (low + high) / 2;
        if (f(mid)) low = mid + 1, ans = mid;
        else high = mid - 1;
    }

    cout << ans << '\n';
    return 0;
}
