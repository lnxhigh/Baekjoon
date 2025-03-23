#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 50005;

int N, K;
int A[MAX];
int S[MAX];
int L[MAX], R[MAX];

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> K;

    int sum = 0;
    for (int i = 0; i < K; i++) {
        sum += A[i];
        S[i] = sum;
        L[i] = sum;
    }

    for (int i = K; i < N; i++) {
        sum += A[i] - A[i - K];
        S[i] = sum;
        L[i] = max(L[i - 1], sum);
    }

    sum = 0;
    for (int i = N - 1; i > N - K - 1; i--) {
        sum += A[i];
        R[i] = sum;
    }
    for (int i = N - K - 1; i >= 0; i--) {
        sum += A[i] - A[i + K];
        R[i] = max(R[i + 1], sum);
    }

    int ans = 0;
    for (int i = 1; i + K < N; i++) {
        ans = max(ans, L[i - 1] + S[i - 1 + K] + R[i + K]);
    }
    cout << ans << '\n';
    
    return 0;
}
