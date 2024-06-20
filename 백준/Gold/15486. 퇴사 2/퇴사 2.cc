#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 1500002;

int T[N_MAX], P[N_MAX];
int D[N_MAX][2];

int f(int N) {

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    for (int i = N; i >= 1; i--) {
        D[i][0] = max(D[i+1][0], D[i+1][1]);
        if (i + T[i] - 1 > N) D[i][1] = 0;
        else D[i][1] = max(D[i+T[i]][0], D[i+T[i]][1]) + P[i];
    }

    cout << max(D[1][0], D[1][1]) << '\n';
    return 0;
}
