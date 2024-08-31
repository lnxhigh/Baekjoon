#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N;
const int MAX = 1 << 13, INF = 1 << 30;
int A[MAX], X[MAX];

int main() {
    FastIO
    cin >> N;
    for (int i = 1; i <= N; i++) { cin >> A[i]; }
    A[0] = INF; X[0] = -1;

    int L = 0;
    for (int i = 1; i <= N; i++) {
        int res = L+1;
        int low = 1, high = L+1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[X[mid]] >= A[i]) { res = mid; high = mid - 1; }
            else { low = mid + 1; }
        }

        X[res] = i;
        if (res > L) L = res;
    }

    cout << L << '\n';
    return 0;
}
