#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 100005;

string S, T;
int D[MAX][26]; // index i 이상에서 알파벳의 최초 등장 시점

int solve() {
    memset(D, -1, sizeof(D));
    for (int i = 0; i < (int) T.size(); i++) {
        D[i][T[i] - 'a'] = i;
    }
    
    for (int a = 0; a < 26; a++) {
        stack<int> st;

        for (int i = 0; i < (int) T.size(); i++) {
            if (D[i][a] == -1) {
                st.push(i);
            }
            else {
                while (!st.empty()) {
                    D[st.top()][a] = D[i][a];
                    st.pop();
                }
            }
        }
    }

    for (int i = 0; i < (int) S.size(); i++) {
        if (D[0][S[i] - 'a'] == -1) return -1;
    }

    int cnt = 1, cur = 0;
    for (int i = 0; i < (int) S.size(); i++) {
        int nxt = D[cur][S[i] - 'a'];
        
        if (nxt != -1) {
            cur = nxt + 1;
        }
        else {
            cnt++;
            cur = D[0][S[i] - 'a'] + 1;
        }
    }

    return cnt;
}

int main() {
    FastIO
    cin >> S >> T;
    int ans = solve();
    cout << ans << '\n';
    return 0;
}
