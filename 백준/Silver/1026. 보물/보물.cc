#include <bits/stdc++.h>
using namespace std;

int N, X;
const int N_MAX = 50;
int A[N_MAX], B[N_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++) { cin >> A[i]; }
    for (int i = 0; i < N; i++) { cin >> B[i]; }
    
    sort(A, A + N); sort(B, B + N);
    for (int i = 0; i < N; i++) { X += A[N-1-i] * B[i]; }
    cout << X << '\n';
    return 0;
}
