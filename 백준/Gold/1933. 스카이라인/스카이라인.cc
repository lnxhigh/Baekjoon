#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 200005;

// Input
int N;
tuple<int,int,int> Info[MAX];

// Compress
vector<int> X;
map<int,int> T;
map<int,int> Y;

// Solve
int Warp[MAX], Height[MAX];

void input() {
    cin >> N;
    X.reserve(N << 1);

    for (int i = 0; i < N; i++) {
        int L, H, R; cin >> L >> H >> R;
        Info[i] = { H, L, R };
        X.push_back(L); X.push_back(R);
    }
}

void compress() {
    sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());
    for (int i = 0; i < (int) X.size(); i++) {
        T[X[i]] = i, Y[i] = X[i];
    }

    for (int i = 0; i < N; i++) {
        auto& [H, L, R] = Info[i];
        L = T[L], R = T[R];
    }
}

void solve() {
    sort(Info, Info + N);
    memset(Warp, -1, sizeof(Warp));

    for (int i = N - 1; i >= 0; i--) {
        auto [H, L, R] = Info[i];
        while (Warp[R] != -1) R = Warp[R];

        for (int x = L; x < R; x++) {
            while (Warp[x] != -1) x = Warp[x];
            if (x >= R) break;
            
            Warp[x] = R;
            Height[x] = H;
        }
    }

    for (int i = 0; i < (int) X.size(); i++) {
        if (i == 0 || Height[i - 1] != Height[i]) {
            cout << Y[i] << ' ' << Height[i] << ' ';
        }
    }
    cout << '\n';
}

int main() {
    FastIO
    input();
    compress();
    solve();    
    return 0;
}
