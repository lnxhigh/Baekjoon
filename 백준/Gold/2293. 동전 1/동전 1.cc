#include <bits/stdc++.h>
using namespace std;

int N, K;
const int N_MAX = 101;
const int K_MAX = 10001;
int C[N_MAX];
int D[K_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    
    // 기존 구현 - 이차원 배열 사용
    // 그런데 메모리 부족 및 착각으로 구현 실패함
    
    // D[n][k] 를 n번째 아이템까지 있을 때 가치의 합이 K가 되도록 하는 개수로 정의
    // ( Knapsack 이랑 정의 비슷함 )
    // 그러면 k = 1 ~ K 까지 돌면서 다음과 같이 구할 수 있음을 알았다
    // k <  C[n] => D[n][k] = D[n-1][k]
    // k == C[n] => D[n][k] = D[n-1][k] + 1
    // k >  C[n] => D[n][k] = D[n-1][k] + D[n-1][k-C[n]]

    // 메모리를 최적화하면 아래와 같이 된다 (...)
    // 오늘도 멍청함을 깨닫는다

    D[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int k = C[i]; k <= K; k++) {
            D[k] += D[k - C[i]];
        }
    }

    cout << D[K] << '\n';
    return 0;
}
