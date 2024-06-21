#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
const int N_MAX = 100000;
int A[N_MAX];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        pq.push(A[i]);
    }

    ll res = 0;
    while (pq.size() >= 2) {
        int k = 0;
        k += pq.top(); pq.pop();
        k += pq.top(); pq.pop();
        pq.push(k);
        res += 1LL * k;
    }

    cout << res << '\n';
    return 0;
}
