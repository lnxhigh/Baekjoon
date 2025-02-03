#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N, T;
int A[16];

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> T;

    int cnt = 0;
    sort(A, A + N);
    
    for (int i = 0; i < N; i++) 
        for (int j = i + 1; j < N; j++) 
            if (A[j] - A[i] <= (T * 2)) cnt++;

    double ans = cnt / 4.0;
    cout << ans << '\n';
    return 0;
}
