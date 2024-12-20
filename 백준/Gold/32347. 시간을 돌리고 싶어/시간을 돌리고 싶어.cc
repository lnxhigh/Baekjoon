#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 200001;

int N, K;
bool A[MAX];
int  D[MAX];

bool f(int t) {
    int cur = N - 1;
    int cnt = 0;
    
    while (cur && A[cur]) {
        cnt++;
        int nxt = max(cur - t, 0);
        nxt = D[nxt];
        if (nxt >= cur) return false;
        cur = nxt;
    }

    return cur == 0 && cnt <= K;
}

int main() {
    FastIO
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    A[0] = true;

    stack<int> st;
    fill(D, D + N, N);
    for (int i = 0; i < N; i++) {
        if (!A[i]) { st.push(i); continue; }
        
        D[i] = i;
        while (!st.empty()) { D[st.top()] = i; st.pop(); }
    }

    int ans = -1;
    int low = 1, high = N - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (f(mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
