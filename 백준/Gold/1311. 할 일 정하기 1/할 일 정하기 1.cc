#include <bits/stdc++.h>
#define INF 1 << 20
#define N_MAX 20
using namespace std;

int N;
int D[N_MAX][N_MAX];
int C[N_MAX][1 << N_MAX];
vector<int> bits[N_MAX+1];

// C[i][k] : 현재까지 i까지의 일을 했고 지금까지 일한 사람이 k 일 때 최소 비용

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> D[i][j];
        }
    }

    fill(&C[0][0], &C[N_MAX-1][(1 << N_MAX) - 1] + 1, INF);
    for (int i = 0; i < N; i++) {
        C[0][1 << i] = D[i][0];
    }

    for (int bit = 0; bit < (1 << N); bit++) {
        int cnt = 0;
        for (int k = 0; k < N; k++) {
            if (bit & (1 << k)) cnt++;
        }
        bits[cnt].push_back(bit);
    }

    for (int work = 1; work < N; work++) {
        for (const int &state : bits[work]) {
            for (int person = 0; person < N; person++) {
                if (state & (1 << person)) continue;

                int newState = state + (1 << person);
                int newCost = C[work-1][state] + D[person][work];
                C[work][newState] = min(C[work][newState], newCost);
            }        
        }   
    }
    
    cout << C[N-1][(1<<N)-1];
    return 0;
}
