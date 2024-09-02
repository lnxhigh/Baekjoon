#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N;
const int MAX = 10000;
pair<double,int> A[MAX];

int main() {
    FastIO
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        double force, ring;
        cin >> force >> ring;
        double perf = (ring - 1) / force;
        A[i] = { perf, i+1 };
    }

    sort(A, A + N);
    for (int i = N-1; i >= 0; i--) {
        cout << A[i].second << '\n';
    }
    return 0;
}
