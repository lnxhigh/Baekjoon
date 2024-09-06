#include <bits/stdc++.h>
using namespace std;

int N, D;

string f(int X, int D) {
    if (X < D) return to_string(X);
    return f(X / D, D) + f(X % D, D);
}

int g(string X, int D) {
    if (X == "-1") return -1;
    int res = 0, mul = 1;

    for (int i = (int) X.size() - 1; i >= 0; i--) {
        int d = (int) (X[i] - '0');
        res += d * mul;
        mul *= D;
    }
    return res;
}

int main() {
    cin >> N >> D;
    string target = f(N, D);
    
    string cur;
    string res = "-1";
    for (int i = 0; i < D; i++) {
        cur.push_back(i + '0');
    }

    do {
        if (cur[0] == '0') continue;
        if (cur.size() > target.size() || (cur.size() == target.size() && cur > target)) {
            res = cur;
            break;
        }
    } while (next_permutation(cur.begin(), cur.end()));
    
    cout << g(res, D) << '\n';
    return 0;
}

