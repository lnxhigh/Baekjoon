#include <string>
#include <vector>

using namespace std;

const int MAX = 100001;
const long long MOD = 1000000007LL;
long long dp[MAX];

int solution(int n, vector<int> money) {
    dp[0] = 1;
    for (int m : money) {
        for (int x = m; x <= n; x++) {
            dp[x] += dp[x - m];
        }
    }

    return dp[n];
}
