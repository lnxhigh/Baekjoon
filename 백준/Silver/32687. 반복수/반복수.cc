#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    int64 A, B, K, M;
    cin >> A >> B >> K >> M;
    
    int64 cnt = 0;
    int64 S = 1;

    for (int64 i = 1; i < K; i++) S *= 10;
    int64 MUL = S * 10;

    for (int64 i = S; i < S * 10; i++) {
        // i에 대해 K 반복수 생성
        int64 x = i;

        while (x <= B) {
            x = x * MUL + i;
        }

        while (x >= i) {
            if (x >= A && x <= B) {
                if (x % M == 0) {
                    cnt++;
                }
            }
            x /= 10;
        }
    }

    cout << cnt << '\n';
    return 0;
}
