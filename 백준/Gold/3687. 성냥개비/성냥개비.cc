#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using ll = long long;
const int MAX = 1 << 7;

int T;
int L[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
string D[MAX];

bool isLess(string x, string y) {
    if (x.size() != y.size()) return x.size() < y.size();
    return x < y;
}

string smallest(int n) {
    if (n == 0) return "";
    if (D[n] != "") return D[n];

    string ret = "";
    
    for (int i = 0; i < 10; i++) {
        int len = n - L[i];
        if (len < 0 || len == 1) continue;
        
        string x = smallest(len);

        string nxt = x + to_string(i);
        if (nxt != "0") {
            if (ret == "" || isLess(nxt, ret)) ret = nxt;
        }

        if (i == 0) continue;

        nxt = to_string(i) + x;
        if (ret == "" || isLess(nxt, ret)) ret = nxt;
    }

    return D[n] = ret;
}

string largest(int n) {
    string ret = (n & 1) ? "7" : "1";
    n /= 2, n--;

    for (int i = 0; i < n; i++) ret.push_back('1');
    return ret;
}

int main() {
    FastIO
    cin >> T;
    while (T--) {
        int N; cin >> N;
        cout << smallest(N) << ' ' << largest(N) << '\n';
    }
    return 0;
}
