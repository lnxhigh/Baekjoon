#include <bits/stdc++.h>
#define N_MAX 101
using namespace std;

int N, M;
int X[N_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i <= N; i++) X[i] = i;
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        reverse(X + A, X + B + 1);
    }
    for (int i = 1; i <= N; i++) cout << X[i] << ' ';
    cout << '\n';
    return 0;
}
