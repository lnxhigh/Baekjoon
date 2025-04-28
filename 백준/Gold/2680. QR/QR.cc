#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int len[4];
int chunk[4];
int arr[4][4];

string alphanum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:";

char f(int x) {
    if (x >= 10) return 'A' + (x - 10);
    return '0' + x;
}

void print(int idx, int x, int cnt) {
    std::ostringstream oss;
    
    if (idx == 0) {
        oss << std::setw(cnt) << std::setfill('0') << x;
        cout << oss.str();
    }
    else if (idx == 1) {
        if (cnt > 1) cout << alphanum[x / 45] << alphanum[x % 45];
        else cout << alphanum[x];
    }
    else if (idx == 2) {
        oss << std::setw(2) << std::setfill('0') << std::hex << std::uppercase << x;
        if (x < 0x20 || x > 0x7e) {
            cout << "\\" << oss.str();
        }
        else {
            char c = (char) x;
            if (c == '\\') cout << "\\\\";
            else if (c == '#') cout << "\\#";
            else cout << c;
        }
    }
    else if (idx == 3) {
        oss << std::setw(4) << std::setfill('0') << std::hex << std::uppercase << x;
        cout << "#" << oss.str();
    }
}

int main() {
    FastIO
    int tc; cin >> tc;

    len[0] = 10, len[1] = 9, len[2] = 8, len[3] = 8;
    chunk[0] = 3, chunk[1] = 2, chunk[2] = 1, chunk[3] = 1;

    arr[0][1] = 4, arr[0][2] = 7, arr[0][3] = 10;
    arr[1][1] = 6, arr[1][2] = 11;
    arr[2][1] = 8, arr[3][1] = 13;

    while (tc--) {
        string hexa; cin >> hexa;
        
        string bits;

        int ans = 0;
        vector<tuple<int,int,int>> result;

        for (char c : hexa) {
            int num = isdigit(c) ? (c - '0') : (c - 'A' + 10);
            string binary = bitset<4>(num).to_string();
            bits += binary;
        }

        size_t pos = 0;

        while (pos + 4u <= bits.size()) {
            int mode = stoi(bits.substr(pos, 4), nullptr, 2);
            pos += 4;

            if (mode == 0) break;
            
            int idx = 0;
            while ((mode >> idx & 1) == 0) idx++;

            int cnt_len = len[idx];

            int cnt = stoi(bits.substr(pos, cnt_len), nullptr, 2);
            pos += cnt_len;
            
            while (pos < bits.size() && cnt > 0) {
                int chunk_cnt = min(chunk[idx], cnt);
                int chunk_len = arr[idx][chunk_cnt];
                int x = stoi(bits.substr(pos, chunk_len), nullptr, 2);

                cnt -= chunk_cnt;
                pos += chunk_len;

                ans += chunk_cnt;
                result.push_back({ idx, x, chunk_cnt });
            }
        }

        cout << ans << ' ';
        for (auto [idx, x, cnt] : result) print(idx, x, cnt);
        cout << '\n';
    }

    return 0;
}
