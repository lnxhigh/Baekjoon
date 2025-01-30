#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const long long INF = 2'147'483'647;

int K, N;
int P[101];
int A[100001];
int D[101];

int main() {
    FastIO
    cin >> K >> N;
    for (int i = 0; i < K; i++) cin >> P[i];

    A[0] = 1;
    for (int i = 1; i <= N; i++) {
        long long nxt = INF;
        for (int k = 0; k < K; k++) {
            long long tmp = (long long) P[k] * A[D[k]];
            nxt = min(nxt, tmp);
        }

        A[i] = nxt;
        for (int k = 0; k < K; k++) {
            long long tmp = (long long) P[k] * A[D[k]];
            if (nxt == tmp) D[k]++;
        }
    }
    
    cout << A[N] << '\n';
    return 0;
}
