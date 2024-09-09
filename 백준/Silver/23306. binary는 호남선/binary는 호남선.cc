#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int query(int x) {
    cout << '?' << ' ' << x << endl;
    int y; cin >> y;
    return y;
}

int main() {
    FastIO
    int N; cin >> N;
    int s = query(1);
    int e = query(N);
    cout << '!' << ' ' << e - s << endl;
    return 0;
}
