#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const long long INF = 2'147'483'647;

int K, N;
int P[101];
int A[100001];

int main() {
    FastIO
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> P[i];
    }

    A[0] = 1;
    for (int i = 1; i <= N; i++) {
        int cur = A[i - 1];
        int nxt = INF;

        for (int k = 0; k < K; k++) {
            int idx = -1;
            int value = cur / P[k];
            int low = 0, high = i - 1;

            while (low <= high) {
                int mid = (low + high) / 2;
                if (A[mid] > value) idx = mid, high = mid - 1;
                else low = mid + 1;
            }
            
            long long tmp = 1LL * A[idx] * P[k];
            if (tmp < INF) nxt = min(nxt, (int) tmp);
        }

        A[i] = nxt;
    }

    int ans = A[N];
    cout << ans << '\n';
    return 0;
}
