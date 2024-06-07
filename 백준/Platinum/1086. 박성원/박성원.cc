#include <bits/stdc++.h>
#define ll long long
#define N_MAX 15
#define M_MAX 100
#define L_MAX 51
using namespace std;

int N, K;
string A[N_MAX];
ll D[M_MAX][1 << N_MAX];
int Mod[N_MAX];
int ten[L_MAX];

// D[m][i] : 현재 상태가 i 일 때 모든 문자열을 이어붙인 순열을 
// K 로 나눈 나머지가 m 인 순열의 개수
// 나머지 상태를 저장함으로써 다음 상태를 업데이트할 때 사용할 수 있다

// Mod : A[i] 를 K 로 나눈 나머지를 저장
// ten : 10 ** s 를 K 로 나눈 나머지를 저장

// a ** b % K 를 계산 --- 10 ** M 을 계산하기 위해 활용
// 이진법 이용 - 희소 행렬 계산 원리와 동일 
// 또는 분할 정복을 이용한 거듭제곱으로 볼 수도 있음
int power(int a, int b, int K) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % K;
        b = b >> 1;
        a = (a * a) % K;
    }
    return res;
}

// 큰 수에 대한 모듈러
int mod(string s, int K) {
    int M = s.size();
    int res = 0;
    for (int i = 0; i < M; i++) {
        int d = s[M-1-i] - '0';
        res += power(10, i, K) * d;
    }
    
    return res % K;
}

// 기약분수 출력을 위한 GCD
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> K;

    for (int i = 0; i < N; i++) {
        Mod[i] = mod(A[i], K);
        D[Mod[i]][1 << i] = 1LL;
    }
    for (int i = 0; i < L_MAX; i++) {
        ten[i] = power(10, i, K);
    }

    for (int state = 0; state < (1 << N); state++) {
        for (int k = 0; k < N; k++) {
            if ((state & (1 << k))) continue;

            int s = A[k].size();
            for (int m = 0; m < K; m++) {
                int newMod = (ten[s] * m + Mod[k]) % K;
                D[newMod][state | (1 << k)] += D[m][state];
            }
        }
    }

    ll p = D[0][(1 << N) - 1], q = 1LL;
    for (int i = 0; i < N; i++) {
        q *= 1LL * (i + 1);
    }

    ll r = gcd(p, q);
    p /= r, q /= r;
    cout << p << '/' << q << '\n';

    return 0;
}
