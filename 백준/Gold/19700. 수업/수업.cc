#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 500005;

int N;
pair<int,int> A[MAX];

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        int H, K; cin >> H >> K;
        A[i] = { H, K };
    }
    sort(A, A + N);

    multiset<int> S;
    for (int i = N - 1; i >= 0; i--) {
        auto [H, K] = A[i];
        auto iter = S.lower_bound(K);
        
        if (iter == S.begin()) {
            S.insert(1);
        }
        else {
            int cnt = *(--iter);
            S.erase(iter);
            S.insert(cnt + 1);
        }
    }

    cout << S.size() << '\n';
    return 0;
}
