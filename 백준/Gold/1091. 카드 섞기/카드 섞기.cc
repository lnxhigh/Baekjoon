#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 48;
const int INF = 1 << 20;
int P[N_MAX], S[N_MAX];
int D[N_MAX][N_MAX]; // i번째 카드를 j번째로 보내는 최단 거리
int X[N_MAX][N_MAX]; // i번째 카드를 k번 섞었을 때 변화하는 위치

bool check(int k) {
    for (int i = 0; i < N; i++) {
        if (P[i] != X[i][k % D[i][i]] % 3) return false;
    }
    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> P[i];
    for (int i = 0; i < N; i++) cin >> S[i];
    
    // 최단 거리 업데이트
    fill(&D[0][0], &D[N_MAX-1][N_MAX-1] + 1, INF);
    for (int i = 0; i < N; i++) { D[i][S[i]] = 1; }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }

    // 카드 섞기 시뮬레이션
    for (int i = 0; i < N; i++) {
        int k = i;
        for (int j = 0; j < N; j++) {
            X[i][j] = k;
            k = S[k];
        }
    }

    // 최대로 카드를 섞을 수 있는 횟수
    set<int> A;
    for (int i = 0; i < N; i++) {
        int k = i;
        for (int j = 0; j < N; j++) {
            if (D[i][j] < INF) k = min(k, j);
        }
        A.insert(k);
    }

    int mul = 1;
    for (int k : A) mul *= D[k][k];

    // 결과 출력
    int res = -1;
    for (int i = 0; i < mul; i++) {
        if (check(i)) {
            res = i;
            break;
        }
    }

    cout << res << '\n';

    return 0;
}
