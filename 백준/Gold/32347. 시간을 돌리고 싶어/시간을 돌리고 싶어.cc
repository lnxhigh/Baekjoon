#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 200001;

int N, K;
bool A[MAX];

bool f(int t) {
    int cur = N - 1;
    int cnt = K;

    while (cnt--) {
        int nxt = cur - t;
        if (nxt <= 0) return true;
        while (!A[nxt]) nxt++;
        if (nxt == cur) return false;
        cur = nxt;
    }

    return false;
}

int main() {
    FastIO
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = -1;
    int low = 1, high = N - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (f(mid)) ans = mid, high = mid - 1;
        else low = mid + 1;
    }

    cout << ans << '\n';
    return 0;
}
