#include <bits/stdc++.h>
using namespace std;

int A, B, C;
const int MAX = 21;
int D[MAX][MAX][MAX];

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);

    if (D[a][b][c] != -1) return D[a][b][c];
    if (a < b && b < c) return D[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    return D[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

void print(int a, int b, int c) {
    cout << 'w' << '(' << a << ',' << ' ' << b << ',' << ' ' << c << ')';
    cout << ' ' << '=' << ' ' << w(a, b, c) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(D, -1, sizeof(D));
    D[0][0][0] = 1;
    while (true) {
        cin >> A >> B >> C;
        if (A == -1 && B == -1 && C == -1) break;
        print(A, B, C);
    }

    return 0;
}
