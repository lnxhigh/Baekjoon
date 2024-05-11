#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int N, M, K, X;
vector<int> arr;
int dp[101][1000] = {0,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        cin >> X;
        arr.push_back(X);
        if (X != 0) dp[1][X % K]++;
    }

    for (int i = 1; i < M; i++) {
        for (int n : arr) {
            for (int k = 0; k < K; k++) {
                int r = (k * (10 % K) + n) % K;
                dp[i+1][r] += dp[i][k];
                dp[i+1][r] %= MOD;
            }
        }
    }

    cout << dp[M][0] << '\n';

    return 0;
}
