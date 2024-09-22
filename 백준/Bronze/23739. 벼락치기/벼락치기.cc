#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> T(N);
    for (int &x : T) cin >> x;

    int R = 30;
    int cnt = 0;
    
    for (int i = 0; i < N; i++) {
        int X = min(T[i], R);
        if (T[i] <= (X << 1)) cnt++;
        
        R -= X;
        if (R == 0) R = 30;
    }

    cout << cnt << '\n';
    return 0;
}
