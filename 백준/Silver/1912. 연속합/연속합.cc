#include <bits/stdc++.h>
#define N_MAX 100001
using namespace std;

int N;
int A[N_MAX];
int D[N_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        D[i+1] = D[i] > 0 ? D[i] + A[i+1] : A[i+1];
    }

    int answer = *max_element(D + 1, D + N+1);
    cout << answer << '\n';
    
    return 0;
}
