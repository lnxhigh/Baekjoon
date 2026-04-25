#include <iostream>
#define INF 2147483647
using namespace std;

int A, B;
int ans = INF;
int cnt = 1;
int Min(int x, int y) { return x < y ? x : y ; }

void search(int N) {
    if (N < A) {
        return;
    }
    else if (N == A) {
        ans = Min(ans, cnt);
        return;
    }
    if (N % 10 == 1) {
        cnt++;
        search((N-1) / 10);
        cnt--;
    }
    if (N % 2 == 0) {
        cnt++;
        search(N / 2);
        cnt--;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> A >> B;
    search(B);
    if (ans == INF) ans = -1;
    cout << ans;
    
    return 0;
}