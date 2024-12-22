#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = (1 << 20) + 5;

int N, Q;
bool occupied[MAX];

int f(int x) {
    int last = 0;
    for (int i = x; i; i >>= 1) {
        if (occupied[i]) {
            last = i;
        }
    }
    
    if (last) return last;
    occupied[x] = true;
    return 0;
}

int main() {
    FastIO
    cin >> N >> Q;
    for (int i = 0; i < Q; i++) {
        int x; cin >> x;
        cout << f(x) << '\n';
    }
    return 0;
}
