#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAXN = 1 << 11;
const int MAXV = 1 << 21;

int S, M, N;
int A[MAXN], B[MAXN];
int X[MAXV], Y[MAXV];

void f(int* arr, int size, int* value) {
    for (int len = 0; len <= size; len++) {
        int sum = 0;
        
        for (int i = 0; i < len; i++) {
            sum += arr[i];
        }
        value[sum]++;
        if (len == 0 || len == size) continue;

        for (int i = 0; i < size - 1; i++) {
            sum += arr[len + i] - arr[i];
            value[sum]++;
        }
    }
}

int main() {
    FastIO
    cin >> S >> M >> N;
    for (int i = 0; i < M; i++) {
        cin >> A[i];
        A[i + M] = A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        B[i + N] = B[i];
    }

    f(A, M, X);
    f(B, N, Y);

    long long ans = 0;
    for (int i = 0; i <= S; i++) {
        long long cnt = (long long) X[i] * Y[S - i];
        ans += cnt;
    }

    cout << ans << '\n';
    return 0;
}
