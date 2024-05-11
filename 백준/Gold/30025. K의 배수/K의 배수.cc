#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007LL
using namespace std;

ll N, M, K;
vector<ll> arr;

ll dp[101][1000] = {0,};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M >> K;
    for (ll i = 0; i < N; i++) 
    {
        ll x;
        cin >> x;
        arr.push_back(x);
    }

    for (ll n : arr)
    {
        if (n == 0) continue;
        dp[1][n % K]++;
    }

    for (ll i = 1; i < M; i++)
    {
        for (ll n : arr)
        {
            for (ll k = 0; k < K; k++)
            {
                ll remain = (k * (10LL % K) + n) % K;
                dp[i+1][remain] += dp[i][k];
                dp[i+1][remain] %= MOD;
            }
        }
    }

    cout << dp[M][0];

    return 0;
}
