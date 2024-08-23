#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define X first
#define Y second
using namespace std;

int N;
const int MAX  = 1 << 16;
int S[MAX], D[MAX];

// ...
// https://blog.naver.com/programmer18/220794470677

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        S[i] = x + y;
        D[i] = x - y;
    }

    int A = *max_element(S, S + N) - *min_element(S, S + N);
    int B = *max_element(D, D + N) - *min_element(D, D + N);
    cout << max(A, B) << '\n';
    return 0;
}
