#include <iostream>
#define K 1000000000;
using namespace std;

int dp[101][10] = {0,};
int N = 0, cnt = 0;

int main(void) {
    cin >> N;

    for (int i = 0; i <= 9; i++) {
        dp[0][i] = 1;
    }

    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= 8; i++) { 
        dp[1][i] = 2; 
    }
    dp[1][9] = 1;

    for (int n = 2; n <= 100; n++) {
        dp[n][0] = dp[n-1][1] % K;
        for (int i = 1; i <= 8; i++) { 
            dp[n][i] = (dp[n-1][i+1] + dp[n-1][i-1]) % K; 
        }
        dp[n][9] = dp[n-1][8] % K;
    }
    
    for (int i = 0; i <= 9; i++) {
        cnt = (dp[N-1][i] + cnt) % K;
    }
    
    if (N == 1) cnt--;
    cout << cnt << '\n';
}
