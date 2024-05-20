#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

int N;
unordered_map<int,int> pre;

int n_digit(int x) {
    int res = to_string(x).size();
    return res;
}

int f(string s, bool maximize) {
    int t = s.size();
    if (t == 1) return stoi(s) & 1 ? 1 : 0;

    int cur = 0;
    for (int k = 0; k < t; k++) {
        cur += f(s.substr(k, 1), maximize);
    }
    
    if (t <= 2) {
        return cur + f(to_string(stoi(s.substr(0, 1)) + stoi(s.substr(1, 1))), maximize);
    }

    int res = maximize ? -INF: INF;

    for (int i = 1; i < t; i++) {
        for (int j = i+1; j < t; j++) {
            vector<pair<int,int>> pairs = { {0, i}, {i, j-i}, {j, t-j} };
            int newNum = 0;

            for (pair<int,int> p : pairs) {
                int pos = p.first, len = p.second;
                newNum += stoi(s.substr(pos, len));
            }
            
            int tmp = cur + f(to_string(newNum), maximize);
            res = maximize ? max(res, tmp) : min(res, tmp);
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    cout << f(to_string(N), false) << ' ';
    cout << f(to_string(N), true) << '\n';

    return 0;
}
