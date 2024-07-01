#include <bits/stdc++.h>
using namespace std;

string S;
int N, L;
const int N_MAX = 51, L_MAX = 51;
string words[N_MAX];

bool C[N_MAX][L_MAX];
int D[L_MAX];
const int INF = 1 << 20;

bool check(int i, int k) {
    int len = words[i].size();
    if (k + len > L) return false;

    int cnt[26];
    memset(cnt, 0, sizeof(cnt));

    for (int x = 0; x < len; x++) {
        cnt[words[i][x]-'a']++;
        cnt[S[k+x]-'a']--;
    }

    for (char c : words[i]) {
        if (cnt[c-'a'] != 0) return false;
    }
    return true;
}

int cost(int i, int k) {
    int res = 0;
    int len = words[i].size();

    for (int x = 0; x < len; x++) {
        if (words[i][x] != S[k+x]) res++;
    }
    return res;
}

int f(int len) {
    if (D[len] != -1) return D[len];
    if (len == 0) return D[len] = 0;

    int res = INF;
    for (int i = 0; i < N; i++) {
        int k = len - words[i].size();
        if (k >= 0 && C[i][k]) res = min(res, f(k) + cost(i, k));
    }
    return D[len] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> S >> N;
    for (int i = 0; i < N; i++) cin >> words[i];
    L = S.size();

    memset(D, -1, sizeof(D));
    for (int i = 0; i < N; i++) {
        for (int k = 0; k <= L; k++) {
            C[i][k] = check(i, k);
        }
    }

    int ans = f(L);
    if (ans >= INF) ans = -1;
    cout << ans << '\n';
    return 0;
}
