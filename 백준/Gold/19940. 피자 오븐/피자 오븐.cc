#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

vector<int> solveA(int N) {
    vector<int> res(5);

    int ADDH = N / 60;
    res[0] = ADDH;
    N %= 60;

    int ADDT = N / 10;
    int ADDO = N % 10;
    int MINO = 10 - N % 10;
    
    int x = ADDT + ADDO;
    int y = ADDT + 1 + MINO;
    
    res[1] = (x <= y) ? ADDT : ADDT + 1;
    res[3] = (x <= y) ? ADDO : 0;
    res[4] = (x <= y) ? 0 : MINO;

    return res;
}

vector<int> solveB(int N) {
    vector<int> res(5);
    
    int ADDH = N / 60 + 1;
    res[0] = ADDH;
    N %= 60;
    N = abs(N - 60);

    int MINT = N / 10;
    int MINO = N % 10;
    int ADDO = 10 - N % 10;
    
    int x = MINT + MINO;
    int y = MINT + 1 + ADDO;
    
    res[2] = (x <= y) ? MINT : MINT + 1;
    res[4] = (x <= y) ? MINO : 0;
    res[3] = (x <= y) ? 0 : ADDO;

    return res;
}

vector<int> solve(int N) {
    vector<int> a = solveA(N);
    vector<int> b = solveB(N);

    int x = 0, y = 0;
    for (int k : a) x += k;
    for (int k : b) y += k;

    if (x != y) return x < y ? a : b;

    for (int i = 0; i < (int) a.size(); i++) {
        if (a[i] == b[i]) continue;
        return (a[i] < b[i]) ? a : b;
    }

    return a;
}

int main() {
    FastIO
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> res = solve(N);
        for (int x : res) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}
