#include <bits/stdc++.h>
using namespace std;

const int MAX = 1 << 10;
bool isPrime[MAX];

void sieve() {
    fill(isPrime, isPrime + MAX, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 0; i < MAX; i++) {
        if (!isPrime[i]) continue;
        for (int j = i+i; j < MAX; j += i) {
            isPrime[j] = false;
        }
    }
}

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    vector<int> yt, yj, common;

    sieve();

    for (int i = 0; i < MAX; i++) {
        if (!isPrime[i]) continue;
        
        bool ab = (i >= A && i <= B);
        bool cd = (i >= C && i <= D);
        if (!ab && !cd) continue;

        vector<int> &v = (ab && cd) ? common : ab ? yt : yj;
        v.push_back(i);
    }

    bool flag = ((int) common.size() % 2 == 0);
    bool res = flag ? yt.size() > yj.size() : !(yt.size() < yj.size());
    string ans = res ? "yt" : "yj";

    cout << ans << '\n';
    return 0;
}
