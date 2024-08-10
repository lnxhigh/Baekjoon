#include <bits/stdc++.h>
using namespace std;

int K;
string state[4];

string rotate(string from, int dir) {
    if      (dir ==  0) return from;
    else if (dir == -1) return from.substr(1, 7) + from.substr(0, 1);
    else if (dir == +1) return from.substr(7, 1) + from.substr(0, 7);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 4; i++) cin >> state[i];
    cin >> K;
    while (K--) {
        int num, dir;
        cin >> num >> dir;

        int dirs[4];
        dirs[--num] = dir;
        for (int x : { -1, +1 }) {
            for (int i = num + x; i >= 0 && i < 4; i += x) { 
                dirs[i] = (state[i-x][4-2*x] == state[i][4+2*x]) ? 0 : -dirs[i-x];
            }    
        }
        for (int i = 0; i < 4; i++) {
            state[i] = rotate(state[i], dirs[i]);
        }
    }

    int res = 0;
    for (int i = 0; i < 4; i++) {
        int k = state[i][0] - '0';
        res += k << i;
    }
    cout << res << '\n';

    return 0;
}
