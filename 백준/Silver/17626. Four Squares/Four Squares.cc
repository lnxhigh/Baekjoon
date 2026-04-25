#include <iostream>
#include <cmath>
#define MAX 50001
using namespace std;

int N;
int dp[MAX] = {0};
int root[MAX] = {0};

int main() {
    cin >> N;

    for (int i = 1; i < MAX; i++) {
        dp[i] = 4;
        root[i] = floor(sqrt(i));
    }

    for (int i = 1; i <= root[MAX-1]; i++) {
        dp[i*i] = 1;
    }

    for (int i = 1; i < MAX; i++) {
        if (dp[i] <= 1) continue;
        for (int k = root[i]; k >= 1; k--) {
            if (dp[i-k*k] == 1) {
                dp[i] = 2;
                break;
            }
        }
    }


    for (int i = 1; i < MAX; i++) {
        if (dp[i] <= 2) continue;
        for (int k = root[i]; k >= 1; k--) {
            if (dp[i-k*k] == 2) {
                dp[i] = 3;
                break;
            }
        }
    }

    cout << dp[N];    
}