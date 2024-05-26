#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K;

    int r = K / N;
    int c = K % N;
    
    ll answer;
    ll start = 1LL, end = 1LL * N * N;
    while (start <= end) {
        ll mid = (start + end) / 2LL;
        ll value = 0;
        for (ll i = 1; i <= N; i++) {
            ll div = mid / i;
            if (div > N) div = N;
            else if (mid % i == 0) div--;
            value += div;
        }

        if (value < K) {
            start = mid + 1;
            answer = mid;
        }
        else {
            end = mid - 1;
        }
    }

    cout << answer << '\n';

    // answer 이상의 존재하는 최소의 수 찾기 ?

    return 0;
}
