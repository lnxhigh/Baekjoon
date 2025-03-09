#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
using uint = unsigned int;
const int MAX = 1 << 10;

int N;
uint D[MAX];

uint encode(string address) {
    uint ret = 0;
    uint idx = 0, cur = 0, nxt = 0;
    uint L = address.size();

    while (nxt < L) {
        while (nxt < L && isdigit(address[nxt])) nxt++;

        uint x = stoi(address.substr(cur, nxt - cur));
        uint move = 32 - 8 * (idx + 1);
        ret |= x << move;

        ++idx;
        cur = ++nxt;
    }

    return ret;
}

string decode(uint address) {
    string ret = "";
    for (int i = 1; i <= 4; i++) {
        uint move = (32 - 8 * i);
        uint mask = 255 << move;
        uint x = (address & mask) >> move;
        ret += to_string(x);
        ret += ".";
    }

    ret.pop_back();
    return ret;
}

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        string address; cin >> address;
        D[i] = encode(address);
    }

    uint address = 0;
    uint mask = 0;

    for (int m = 31; m >= 0; m--) {
        bool chk = true;
        uint bit = D[0] >> m & 1;

        for (int i = 0; i < N; i++) {
            if ((D[i] >> m & 1) != bit) {
                chk = false;
                break;
            }
        }

        if (!chk) break;

        address |= bit << m;
        mask |= 1 << m;
    }

    cout << decode(address) << '\n';
    cout << decode(mask) << '\n';

    return 0;
}
