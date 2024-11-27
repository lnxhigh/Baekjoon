#include <iostream>
#include <string>
using namespace std;

int dp[2501];
bool p[2501][2501] = {false,};

string s;
int N;
int Min(int x, int y) { return x < y ? x : y ; } 

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s;
    N = s.size();
    dp[0] = 0; dp[1] = 1;
    
    for (int i = 1; i <= N; i++) {
        p[i][i] = true;
    }
    for (int i = 1; i < N; i++) {
        if (s[i-1] == s[i]) p[i][i+1] = true;
    }
    for (int len = 3; len <= N; len++) {
        for (int start = 1; start + len - 1 <= N; start++) {
            int end = start + len - 1;
            if ((s[start-1] == s[end-1]) && p[start+1][end-1]) p[start][end] = true;
        }
    }    

    for (int i = 2; i <= N; i++) {
        int x = N;
        for (int k = 0; k < i; k++) {
            if (p[k+1][i]) x = Min(x, dp[k]);
        }
        dp[i] = ++x;
    }

    cout << dp[N];
}