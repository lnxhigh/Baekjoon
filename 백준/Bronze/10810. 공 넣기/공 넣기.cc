#include <bits/stdc++.h>
#define N_MAX 101
using namespace std;

int N, M;
int A[N_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        for (int k = x; k <= y; k++) A[k] = z;
    }

    for (int i = 1; i <= N; i++) cout << A[i] << ' ';
    cout << '\n';
    
    return 0;
}
