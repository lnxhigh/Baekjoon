#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 51;

int n;
int arr[MAX][MAX];
int sum[MAX][MAX];

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

    int cnt = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            map<int,int> first, second;

            for (int x = 1; x <= i; x++) {
                for (int y = 1; y <= j; y++) {
                    first[area(x, y, i, j)]++;
                }
            }

            for (int x = i + 1; x <= n; x++) {
                for (int y = j + 1; y <= n; y++) {
                    cnt += first[area(i + 1, j + 1, x, y)];
                }
            }

            for (int x = i + 1; x <= n; x++) {
                for (int y = 1; y <= j; y++) {
                    second[area(i + 1, y, x, j)]++;
                }
            }

            for (int x = 1; x <= i; x++) {
                for (int y = j + 1; y <= n; y++) {
                    cnt += second[area(x, j + 1, i, y)];
                }
            }
        }
    }
    
    cout << cnt << '\n';

    return 0;
}
