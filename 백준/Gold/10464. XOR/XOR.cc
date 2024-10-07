#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

// 정수 i (0 <= i < N) 에 대해
// N 을 X 로 나눈 나머지가 Y 이상인 수의 개수를 구하자

// k번째 비트가 1인 수의 개수는
// 2^(k+1) 으로 나눈 나머지가 2^k 이상인 수의 개수와 같다

int f(int N, int X, int Y) {
    int Q = N / X, R = N % X;
    int L = Q * Y + min(R, Y);
    return N - L;
}

int solve(int S, int F) {
    int res = 0;

    for (int i = 0; i < 30; i++) {
        int k = 1 << i;
        int x = f(S, k << 1, k);
        int y = f(F + 1, k << 1, k);
        
        int cnt = y - x;
        if (cnt & 1) res |= k;
    }

    return res;
}


int main() {
    FastIO

    int T; cin >> T;
    while (T--) {
        int S, F; 
        cin >> S >> F;
        cout << solve(S, F) << '\n';
    }

    return 0;
}
