#include <iostream>
#define N_MAX 1001
#define K 10007
using namespace std;

int N;
int dp[N_MAX];

int main() {
    cin >> N;
    dp[0] = 0; dp[1] = 1; dp[2] = 3;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i-1] + 2*dp[i-2];
        dp[i] %= K;
    }

    cout << dp[N] << '\n';
    return 0;
}