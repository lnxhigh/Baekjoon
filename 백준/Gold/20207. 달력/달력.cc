#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1024;

// Input
int N;
pair<int,int> X[MAX];

// Calendar
bool A[MAX][369];
int D[MAX];

void input() { 
    cin >> N;
    for (int i = 0; i < N; i++) {
        int S, E; cin >> S >> E;
        int len = E - S + 1;
        X[i] = { S, -len };
    }
    sort(X, X + N);
}

void write() {
    for (int i = 0; i < N; i++) {
        auto [S, len] = X[i];
        len = -len;

        int r = 0;
        while (A[r][S]) r++;
        for (int c = S; c < S + len; c++) {
            A[r][c] = true;
            D[c] = max(D[c], r + 1);
        }
    }
}

int solve() {
    int area = 0;
    stack<int> st;

    for (int day = 1; day <= 366; day++) {
        if (D[day]) {
            st.push(day);
        }
        else {
            int w = st.size(), h = 0;
            while (!st.empty()) h = max(h, D[st.top()]), st.pop(); 
            area += w * h;
        }
    }

    return area;
}

int main() {
    FastIO
    input();
    write();
    int ans = solve();
    cout << ans << '\n';
    return 0;
}
