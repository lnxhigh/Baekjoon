#include <bits/stdc++.h>
using namespace std;

int N, K;

int main() {
    cin >> N >> K;
    
    int cnt = 0;
    int target = 0;
    for (int i = 1; i <= N; i++) {
        if (N % i != 0) continue;
        cnt++;
        if (cnt == K) target = i;
    }

    cout << target << '\n';
    return 0;
}
