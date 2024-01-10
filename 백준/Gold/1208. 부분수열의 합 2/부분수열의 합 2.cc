#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll N, S;
ll arrLeft[20], arrRight[20];
ll sumArrLeft[1<<20], sumArrRight[1<<20];
ll sumLeft = 0, sumRight = 0;
ll cntLeft = 0, cntRight = 0;

void f(ll i, ll N, ll S, ll arr[], ll sumArr[], ll& sum, ll& cnt) {
    if (i == N) {
        sumArr[cnt++] = sum;
        return;
    }
    f(i+1, N, S, arr, sumArr, sum, cnt);
    sum += arr[i];
    f(i+1, N, S, arr, sumArr, sum, cnt);
    sum -= arr[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> S;
    ll N1 = (N+1)/2, N2 = N-N1;
    for (ll i = 0; i < N1; i++) { cin >> arrLeft[i]; }
    for (ll i = 0; i < N2; i++) { cin >> arrRight[i]; }

    f(0, N1, S, arrLeft, sumArrLeft, sumLeft, cntLeft);
    f(0, N2, S, arrRight, sumArrRight, sumRight, cntRight);
        
    sort(sumArrLeft, sumArrLeft+cntLeft);
    sort(sumArrRight, sumArrRight+cntRight);

    ll answer = 0;
    for (ll i = 0; i < cntLeft; ++i) {
        auto upperIdx = upper_bound(sumArrRight, sumArrRight + cntRight, S - sumArrLeft[i]);
        auto lowerIdx = lower_bound(sumArrRight, sumArrRight + cntRight, S - sumArrLeft[i]);
        answer += upperIdx - lowerIdx;
    }

    if (S == 0) answer--;    
    cout << answer;
    
    return 0;
}
