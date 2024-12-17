#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 6;

int N, M, K;
int A[MAX];
bool D[MAX];

void input() {
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        cin >> A[i];
    }
}

bool f(int len) {
    int cnt = 1;
    int last = 0;

    for (int i = 1; i < K; i++) {
        int diff = A[i] - A[last];
        if (diff < len) continue;
        
        cnt++;
        last = i;
    }

    return cnt >= M;
}

int solve() {
    int len = 0;
    
    // Max Length
    int low = 0, high = N;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (f(mid)) { len = mid, low = mid + 1; }
        else high = mid - 1;
    }

    // Construct Answer
    D[0] = true;
    int cnt = 1;
    int last = 0;

    for (int i = 1; i < K; i++) {
        int diff = A[i] - A[last];
        if (diff < len) continue;
        if (cnt == M) break;

        D[i] = true;
        cnt++;
        last = i;
    }

    for (int i = 0; i < K; i++) {
        cout << D[i];
    }
    cout << '\n';
    
    return len;
}

int main() {
    FastIO
    input();
    solve();
    return 0;
}
