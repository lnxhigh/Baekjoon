#include <bits/stdc++.h>
#define DIV 1000000003
#define N_MAX 1001
#define K_MAX 1001
using namespace std;

int N, K;
int D[N_MAX][K_MAX][2][2];
// D[i][f][l] - i번째 색까지 인접하지 않게 선택하는 경우의 수
// f는 첫번째 원소를 포함하는지 지시. l은 마지막 원소를 포함하는지 지시

int main() {
    cin >> N >> K;

    D[3][2][1][1] = 1;
    for (int i = 3; i <= N; i++) {
        D[i][1][0][0] = i - 2;
        D[i][1][0][1] = 1;
        D[i][1][1][0] = 1;
    }

    for (int i = 3; i < N; i++) {
        for (int k = 2; k <= N; k++) {
            D[i+1][k][0][0] = (D[i][k][0][0] + D[i][k][0][1]) % DIV;
            D[i+1][k][0][1] = D[i][k-1][0][0];
            D[i+1][k][1][0] = (D[i][k][1][0] + D[i][k][1][1]) % DIV;
            D[i+1][k][1][1] = D[i][k-1][1][0];
        }
    }

    int answer = (D[N][K][0][1] + D[N][K][1][0]) % DIV;
    answer = (answer + D[N][K][0][0]) % DIV;
    cout << answer << '\n';

    return 0;    
}
