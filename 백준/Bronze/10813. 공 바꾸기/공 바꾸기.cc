#include <bits/stdc++.h>
#define N_MAX 101
using namespace std;

int N, M;
int A[N_MAX];

void swap(int x, int y) {
    int tmp = A[x];
    A[x] = A[y];
    A[y] = tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for (int i = 1; i <= N; i++) A[i] = i;
    for (int i = 1; i <= M; i++) {
        int x, y;
        cin >> x >> y;
        swap(x, y);
    }
    for (int i = 1; i <= N; i++) cout << A[i] << ' ';
    cout << '\n';

    return 0;
}
