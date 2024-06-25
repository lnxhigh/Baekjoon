#include <bits/stdc++.h>
using namespace std;

int N, K;
const int L = 25;

int main() {
    cin >> N >> K;
    int res = -1;
    
    for (int bits = N; bits < (1 << L); bits++) {
        int cnt = 0;
        for (int i = 0; i < L; i++) {
            if (bits & (1 << i)) cnt++;
        }
        
        if (cnt <= K) {
            res = bits;
            break;
        }
    }

    // 물병을 안 사도 되면 0을 출력해야 하는지 ???
    // 느낌이 틀릴것같음 ... 일단 0 출력과 -1 출력 둘 다 돌려 보자
    int ans = res - N;
    cout << ans << '\n';
    return 0;
}
