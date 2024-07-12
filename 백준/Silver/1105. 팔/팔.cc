#include <bits/stdc++.h>
using namespace std;

int L, R;

int solve(int L, int R) {
    string l = to_string(L);
    string r = to_string(R);

    int s = r.size();
    int d = r.size() - l.size();
    l = string(d, '0') + l;
    
    int res = 0;
    for (int i = 0; i < s; i++) {
        if (l[i] != r[i]) break;
        if (l[i] == '8' && r[i] == '8') res++;
    }

    return res;
}

int main() {
    cin >> L >> R;
    cout << solve(L, R) << '\n';
    return 0;
}
