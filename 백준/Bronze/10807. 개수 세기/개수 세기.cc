#include <bits/stdc++.h>
#define N_MAX 100
using namespace std;

int N, V;
int A[N_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) { cin >> A[i]; }
    cin >> V;

    int answer = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == V) answer++;
    }
    cout << answer << '\n';
    
    return 0;
}
