#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

const int MAX = 128;
const int INF = 1 << 30;
const string DNA = "ACGT*";
map<char,int> gene;

int Table[5][5] = {
     5, -1, -2, -1, -3,
    -1,  5, -3, -2, -4,
    -2, -3,  5, -2, -2,
    -1, -2, -2,  5, -1,
    -3, -4, -2, -1,  0
};

int M, N;
string A, B;
int D[MAX][MAX];

void init() {
    for (int i = 0; i < (int) DNA.size(); i++) {
        gene[DNA[i]] = i;
    }
}

int f(char x, char y) {
    return Table[gene[x]][gene[y]];
}

int dfs(int i, int j) {
    if (i == -1 || j == -1) {
        int sum = 0;
        for (int k = 0; k <= i; k++) sum += f(A[k], '*');
        for (int k = 0; k <= j; k++) sum += f('*', B[k]);
        return sum;
    }
    else if (D[i][j] != INF) {
        return D[i][j];
    }

    // AGTGATG*
    // GTTA   G
    int first = dfs(i, j - 1) + f('*', B[j]);

    // AGTGATG
    // GTTAG *
    int second = dfs(i - 1, j) + f(A[i], '*');

    // AGTGATG
    // GTTA  G
    int third = dfs(i - 1, j - 1) + f(A[i], B[j]);

    return D[i][j] = max({ first, second, third });
}

int main() {
    FastIO
    init();
    
    int T; cin >> T;
    while (T--) {
        cin >> M; if (M) cin >> A;
        cin >> N; if (N) cin >> B;

        for (int i = 0; i < MAX; i++) {
            fill(D[i], D[i] + MAX, INF);
        }
        int ans = dfs(M - 1, N - 1);
        cout << ans << '\n';
    }

    return 0;
}
