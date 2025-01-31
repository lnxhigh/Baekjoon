#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 20;

int N;
long long K;
int S[MAX], D[MAX];
int P[MAX];

int A[MAX];
bool V[MAX];

int main() {
    FastIO
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> S[i];
    for (int i = 1; i <= N; i++) cin >> D[i];

    for (int i = 1; i <= N; i++) {
        if (P[i]) continue;

        int cnt = 0;
        for (int x = i; !V[x]; x = D[x]) {
            V[x] = true;
            A[cnt++] = x;
        }

        for (int x = 0; x < cnt; x++) { 
            int cur = A[x];
            int nxt = A[(K + x) % cnt];
            P[nxt] = S[cur];
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << P[i] << ' ';
    }
    cout << '\n';
    return 0;
}
