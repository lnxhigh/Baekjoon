#include <bits/stdc++.h>
using namespace std;

int N, M;
const int N_MAX = 1 << 8;
int P[N_MAX];

string solve(int a, int b) {
    if (N <= 1 || P[a] > M) return "0";

    string res = to_string(a);
    int money = M - P[a];
    while (money >= P[b]) {
        res += to_string(b);
        money -= P[b];
    }
    
    int len = res.size();
    for (int i = 0; i < len; i++) {
        int x = res[i] - '0';
        for (int k = N - 1; k > x; k--) {
            int diff = P[k] - P[x];
            if (diff <= money) {
                res[i] = k + '0';
                money -= diff;
                break;
            }
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> P[i];
    cin >> M;

    int a = min_element(P + 1, P + N) - P;
    int b = min_element(P, P + N) - P;

    string ans = solve(a, b);
    cout << ans << '\n';
    return 0;
}
