#include <iostream>
#define K 1000000000
using namespace std;

int N;
int stairs[101][10][1<<10] = {0,}; // len =  N; last digit = i; kth bit = 1 if there is at least one k

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;

    // N == 1
    for (int i = 0; i < 10; i++) {
        stairs[1][i][1 << i] = 1;
    }
    
    // N >= 2
    for (int n = 1; n <= N-1; n++) {
        for (int bit = 0; bit < 1024; bit++) {
            for (int i = 0; i <= 9; i++) {
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

    int ans = 0;
    for (int i = 1; i <= 9; i++) {
        ans = ( ans + stairs[N][i][(1 << 10) - 1] ) % K;
    }
    
    cout << ans << '\n';

    return 0;
}
