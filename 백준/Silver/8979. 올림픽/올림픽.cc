#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 10;

int N, K;
tuple<int,int,int> Medal[MAX];

int main() {
    FastIO
    cin >> N >> K; --K;
    for (int i = 0; i < N; i++) {
        int country;
        int gold, silver, bronze;
        cin >> country; --country;
        cin >> gold >> silver >> bronze;
        Medal[country] = { gold, silver, bronze };
    }

    int cnt = 0;
    auto [myGold, mySilver, myBronze] = Medal[K];
    for (int i = 0; i < N; i++) {
        if (i == K) continue;
        auto [gold, silver, bronze] = Medal[i];
        if (myGold < gold) cnt++;
        if (myGold != gold) continue;
        if (mySilver < silver) cnt++;
        if (mySilver != silver) continue;
        if (myBronze < bronze) cnt++;   
    }

    cout << ++cnt << '\n';
    return 0;
}
