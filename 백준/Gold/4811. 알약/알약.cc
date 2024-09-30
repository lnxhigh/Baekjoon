#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using int64 = long long;

const int MAX = 1 << 5;
int64 D[MAX][MAX];

// 한조각이 w 개, 반조각이 h 개 있을 때 서로 다른 문자열의 개수를 D[w][h] 라 하면
// D[w][h] = D[w-1][h+1] + D[w][h-1] 

// w == 0 일 때는 문자열은 hhh...h 로 한 가지밖에 없다
// h == 0 일 때는 언제나 한 조각 전체가 선택되므로 D[w][h-1] 은 무시한다

int main() {
    FastIO

    for (int i = 0; i < MAX; i++) {
        D[0][i] = 1;
    }
    
    for (int w = 1; w < MAX; w++) {
        D[w][0] = D[w-1][1];
        for (int h = 1; h < MAX; h++) {
            D[w][h] = D[w-1][h+1] + D[w][h-1];
        }
    }
    
    while (true) {
        int N; cin >> N;
        if (!N) break;
        cout << D[N][0] << '\n';
    }

    return 0;
}
