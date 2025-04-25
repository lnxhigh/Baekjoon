#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 51;
const int OFFSET = 2500000;

int n;
int arr[MAX][MAX];
int sum[MAX][MAX];

int t = 1;
int chk[5000001];
int cnt[5000001];

int area(int i, int j, int x, int y) {
    return sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1];
}

int main() {
    FastIO

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
        }
    }

    int ans = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            
            for (int x = 1; x <= i; x++) {
                for (int y = 1; y <= j; y++) {
                    int a = area(x, y, i, j) + OFFSET;
                    cnt[a] *= (chk[a] == t);
                    chk[a] = t, cnt[a]++;
                }
            }

            for (int x = i + 1; x <= n; x++) {
                for (int y = j + 1; y <= n; y++) {
                    int a = area(i + 1, j + 1, x, y) + OFFSET;
                    ans += cnt[a] * (chk[a] == t);
                }
            }

            t++;

            for (int x = i + 1; x <= n; x++) {
                for (int y = 1; y <= j; y++) {
                    int a = area(i + 1, y, x, j) + OFFSET;
                    cnt[a] *= (chk[a] == t);
                    chk[a] = t, cnt[a]++;
                }
            }

            for (int x = 1; x <= i; x++) {
                for (int y = j + 1; y <= n; y++) {
                    int a = area(x, j + 1, i, y) + OFFSET;
                    ans += cnt[a] * (chk[a] == t);
                }
            }

            t++;
        }
    }
    
    cout << ans << '\n';

    return 0;
}
