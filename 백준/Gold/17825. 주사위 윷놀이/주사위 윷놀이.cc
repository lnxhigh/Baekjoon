#include <bits/stdc++.h>
using namespace std;

int A[10];
int R[512], B[512];

void init() {
    for (int i = 0; i < 10; i++) {
        cin >> A[i];
    }

    R[1] = 2;
    for (int i = 2; i < 40; i += 2) {
        R[i] = i + 2;
    }
    
    B[10] = 130, B[130] = 160, B[160] = 190, B[190] = 250;
    B[30] = 280, B[280] = 270, B[270] = 260, B[260] = 250;
    B[20] = 220, B[220] = 240, B[240] = 250;
    B[250] = 300, B[300] = 350, B[350] = 40;
}

int move(int x, int k) {
    int* V = (x % 10) ? R : B;
    while (k--) x = V[x];
    return x;
}

int f(int x) {
    int ret = 0;
    vector<int> loc = { 1, 1, 1, 1 };

    for (int i = 0; i < 10; i++) {
        int mask = 0b11 << (i * 2);
        int k = (x & mask) >> (i * 2);
        
        int cur = loc[k];
        int nxt = move(cur, A[i]);
        if (cur == 0 && nxt == 0) return 0;

        bool check = true;
        for (int t = 0; t < 4; t++) {
            check &= (nxt != loc[t]);
        }
        if (nxt != 0 && !check) return 0;

        loc[k] = nxt;
        int score = (nxt < 100) ? nxt : nxt / 10;
        ret += score;
    }

    return ret;
}

int main() {
    init();

    int ans = 0;
    for (int i = 0; i < (1 << 20); i++) {
        ans = max(ans, f(i));
    }
    cout << ans << '\n';

    return 0;
}
