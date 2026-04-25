#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i < 2*N; i++) {
        int k = abs(i - N);
        cout << string(k, ' ') << string((N - k) * 2 - 1, '*') << '\n';
    }
    
    return 0;
}
