#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 3000;

int N, L;
tuple<int,int,bool> A[MAX];

int f(int x, int len, bool dir, int t) {
    if (len == L) return x;
    t %= (L - len) * 2;
    
    int h = len / 2;
    int l = x - h;
    int r = L - (x + h);
    
    if (dir) {
        if (t < l) return x - t;
        else if (t < l + L - len) return (h) + (t - l);
        else return (L - h) - (t - (l + L - len));
    }
    else {
        if (t < r) return x + t;
        else if (t < r + L - len) return (L - h) - (t - r);
        else return (h) + (t - (r + L - len));
    }
}

int main() {
    FastIO
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        int x, len;
        bool dir;
        cin >> len >> dir;
        x = dir ? L - len / 2 : len / 2;
        A[i] = { x, len, dir };
    }

    int t = 0;
    for (int i = 1; i < N; i++) {
        while (true) {
            auto [x, xlen, xdir] = A[i - 1];
            auto [y, ylen, ydir] = A[i];

            int xnew = f(x, xlen, xdir, t);
            int ynew = f(y, ylen, ydir, t);

            bool canMove = false;
            if (xnew <= ynew) canMove |= (xnew + xlen / 2) >= (ynew - ylen / 2);
            else canMove |= (ynew + ylen / 2) >= (xnew - xlen / 2); 
            
            if (canMove) break;
            else t++;
        } 
    }

    cout << t << '\n';
    return 0;
}
