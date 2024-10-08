#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int MAX = 1 << 19;

int N;
int A[MAX], B[MAX];
int M[MAX << 1]; // Map
int64 F[MAX]; // Fenwick Tree

void update(int i) {
    while (i <= N) { F[i]++; i += i & -i; }
}

int64 sum(int i) {
    int64 x = 0;
    while (i > 0) { x += F[i]; i -= i & -i; }
    return x;
}

int main() {
    FastIO
    cin >> N;
    for (int i = 1; i <= N; i++) { cin >> A[i]; }
    for (int i = 1; i <= N; i++) { cin >> B[i]; M[B[i]] = i; }
    
    int64 x = 0;
    for (int i = N; i >= 1; i--) {
        int k = M[A[i]];
        x += sum(k);
        update(k);
    }

    cout << x << '\n';
    return 0;
}
