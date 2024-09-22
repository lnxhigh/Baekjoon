#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;
const int MAX = 10001;
int64 A[MAX];

int main() {
    FastIO
    
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int64 X; cin >> X; A[X]++;
    }

    // Median
    int64 median = 0;
    int64 K = (N + 1) / 2;

    int64 cur = 0;
    for (int i = 0; i < MAX; i++) {
        int64 next = cur + A[i];
        if (K > cur && K <= next) { median = i; break; }
        cur = next;
    }

    // Mean
    int64 sum = 0, cnt = N;
    for (int64 i = 0; i < MAX; i++) { sum += i * A[i]; }
    int64 mean = sum / cnt;
    if ((sum % cnt) > (cnt / 2)) mean++;

    cout << median << ' ' << mean << '\n';
    return 0;
}
