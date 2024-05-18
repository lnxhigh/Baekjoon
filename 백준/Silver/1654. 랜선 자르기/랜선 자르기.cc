#include <bits/stdc++.h>
#define ll long long
#define K_MAX 10000
using namespace std;

int K, N;
ll len[K_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> len[i];
    }

    ll start = 1;
    ll end = *max_element(len, len + K);
    ll answer;

    while (start <= end) {
        ll mid = start + (end - start) / 2;

        ll value = 0LL;
        for (int i = 0; i < K; i++) {
            value += len[i] / mid;
        }

        if (value >= N) {
            answer = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    cout << answer << '\n';
    
    return 0;
}
