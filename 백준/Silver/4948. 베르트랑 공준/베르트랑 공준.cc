#include <bits/stdc++.h>
#define N_MAX 250000
using namespace std;

bool isPrime[N_MAX];
int cnt[N_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 소수 찾기
    fill(isPrime, isPrime + N_MAX, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 0; i < N_MAX; i++) {
        if (!isPrime[i]) continue;
        for (int j = i + i; j < N_MAX; j = j + i) {
            isPrime[j] = false;
        }
    }

    // i 이하의 소수의 개수 구하기
    int tmp = 0;
    for (int i = 0; i < N_MAX; i++) {
        if (isPrime[i]) tmp++;
        cnt[i] = tmp;
    }

    // 결과 출력
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        int res = cnt[N << 1] - cnt[N];
        cout << res << '\n';
    }

    return 0;
}
