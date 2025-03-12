#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    FastIO
    int N; cin >> N;
    vector<int> A(N);
    for (int &i : A) cin >> i;

    int ans = 0;
    sort(A.begin(), A.end());

    do {
        int sum = 0;
        vector<bool> D(101);
        
        D[0] = true;
        for (int &i : A) {
            sum += i;
            D[sum] = true;
        }
        
        int cnt = 0;
        for (int i = 0; i < 50; i++) {
            if (D[i] && D[i + 50]) cnt++;
        }
        ans = max(ans, cnt);

    } while (next_permutation(A.begin(), A.end()));

    cout << ans << '\n';
    return 0;
}
