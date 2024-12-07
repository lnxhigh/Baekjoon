#include <bits/stdc++.h>
using namespace std;
const int MAX = 1 << 6;

int N;
pair<int,int> A[MAX];
int B[MAX];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        A[i] = { x, i };
    }
    
    sort(A, A + N);
    for (int i = 0; i < N; i++) {
        auto [x, idx] = A[i];
        B[idx] = i;
    }
    for (int i = 0; i < N; i++) {
        cout << B[i] << ' ';
    }
    cout << '\n';
    return 0;
}
