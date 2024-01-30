#include <iostream>
#define N_MAX 100001
using namespace std;

int N;
int map[N_MAX][3];
int dp[2][3]; // line, column
int answer[2];

int max(int* arr, int len) {
    int res = arr[0];
    for (int i = 0; i < len; i++) {
        if (arr[i] > res) { res = arr[i]; }
    }
    return res;
}

int min(int* arr, int len) {
    int res = arr[0];
    for (int i = 0; i < len; i++) {
        if (arr[i] < res) { res = arr[i]; }
    }
    return res;
}

int (*functions[])(int*, int) = { max, min };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    // Input
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int k = 0; k < 3; k++) {
            cin >> map[i][k];
        }
    }

    for (int f = 0; f < 2; f++) {
        for (int k = 0; k < 3; k++) {
            dp[0][k] = map[1][k];
        }

        for (int n = 2; n <= N; n++) {
            for (int k = 0; k < 3; k++) {
                int arr[3];
                int cnt = 0;
                for (int i : { k-1, k, k+1 }) {
                    if (i < 0 || i >= 3) continue;
                    arr[cnt++] = dp[0][i];
                }
                dp[1][k] = functions[f](arr, cnt) + map[n][k];
            }

            for (int k = 0; k < 3; k++) {
                dp[0][k] = dp[1][k];
            }
        }
        
        int arr[3];
        int cnt = 0;
        for (int i = 0; i < 3; i++) {
            arr[cnt++] = dp[0][i];
        }
        answer[f] = functions[f](arr, cnt);
    }
    
    cout << answer[0] << ' ' << answer[1] << '\n';

    return 0;
}