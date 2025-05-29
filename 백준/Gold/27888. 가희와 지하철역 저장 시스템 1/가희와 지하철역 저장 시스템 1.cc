#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int n, r;
int chk[500000];

int ns = 0, nf;
map<string,int> smap, fmap;
int fcnt[1 << 9];

int main() {
    FastIO

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (!smap.count(s)) {
            smap[s] = ns++;
        }
    }

    fcnt[0] = n;

    cin >> r;
    for (int i = 0; i < r; i++) {
        char c; cin >> c;
        string s, fs;

        if (c == 'U') {
            cin >> s >> fs;
            int sidx = smap[s];
            int bits = chk[sidx];
            fcnt[bits]--;

            stringstream ss(fs);
            string f;
            int new_bits = 0;

            while (getline(ss, f, ',')) {
                if (!fmap.count(f)) {
                    fmap[f] = nf++;
                }

                int fidx = fmap[f];
                new_bits |= 1 << fidx;
            }

            chk[sidx] = new_bits;
            fcnt[new_bits]++;
        }
        else if (c == 'G') {
            cin >> fs;

            stringstream ss(fs);
            string f;

            bool flag = true;
            int bits = 0;

            while (getline(ss, f, ',')) {
                if (!fmap.count(f)) flag = false;
                if (!flag) continue;

                int fidx = fmap[f];
                bits |= (1 << fidx);
            }

            if (!flag) {
                cout << 0 << '\n';
            }
            else {
                int sum = 0;

                for (int i = 1; i < (1 << 9); i++) {
                    if ((i & bits) == bits) sum += fcnt[i];
                }
                cout << sum << '\n';
            }
        }
    }
    
    return 0;
}
