#include <iostream>
#define N_MAX 1024
#define ll long long
using namespace std;

int N, M;
int x1, y1, x2, y2;
ll arr[N_MAX+1][N_MAX+1] = {0LL,};
ll sum[N_MAX+1][N_MAX+1] = {0LL,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - ( sum[x1-1][y2] + sum[x2][y1-1] - sum[x1-1][y1-1] ) << '\n';
    }

    return 0;
}