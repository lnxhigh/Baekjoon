#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int cnt = 0, k = 0;

    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (x == k) {
            cnt++;
            k = (k + 1) % 3;
        }
    }
    
    cout << cnt << '\n';
    return 0;
}
