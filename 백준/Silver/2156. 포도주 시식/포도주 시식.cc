#include <bits/stdc++.h>
#define N_MAX 10001
using namespace std;

int N;
int A[N_MAX];
int D[4][N_MAX];
enum { zz, zo, oz, oo };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        D[zz][i+1] = max(D[zz][i], D[oz][i]);
        D[zo][i+1] = max(D[zz][i], D[oz][i]) + A[i+1];
        D[oz][i+1] = max(D[zo][i], D[oo][i]);
        D[oo][i+1] = D[zo][i] + A[i+1];
    }

    int answer = 0;
    for (int k = 0; k < 4; k++)
        for (int i = 1; i <= N; i++)
            answer = max(answer, D[k][i]);
            
    cout << answer << '\n';

    return 0;
}
