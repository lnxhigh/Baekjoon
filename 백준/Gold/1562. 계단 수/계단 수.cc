#include <iostream>
#define K 1000000000LL
#define ll long long
using namespace std;

ll N;
ll stairs[101][10][1<<10] = {0LL,}; // len =  N; last digit = i; kth bit = 1 if there is at least one k

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;

    // N == 1
    for (ll i = 0; i < 10; i++) {
        stairs[1][i][1 << i] = 1;
    }
    
    // N >= 2
    for (ll n = 1; n <= N-1; n++) {
        for (ll bit = 0; bit < 1024; bit++) {
            for (ll i = 0; i <= 9; i++) {
                if (i - 1 >= 0) {
                    stairs[n+1][i-1][bit | (1 << (i-1))] = (
                        stairs[n+1][i-1][bit | (1 << (i-1))] + stairs[n][i][bit]
                    ) % K;
                }
                if (i + 1 <= 9) {
                    stairs[n+1][i+1][bit | (1 << (i+1))] = (
                        stairs[n+1][i+1][bit | (1 << (i+1))] + stairs[n][i][bit]
                    ) % K;
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= 9; i++) {
        ans = ( ans + stairs[N][i][(1 << 10) - 1] ) % K;
    }
    
    cout << ans << '\n';

    return 0;
}
