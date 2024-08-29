#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(false);
using namespace std;

int N;
const int MAX = 1 << 17;
int S[MAX];
stack<int> st;

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    int res = 1;
    int cur = 0;

    while (cur < N) {
        int X = S[cur];
        
        if (st.empty() || X > st.top()) {
            st.push(X);
            cur++;
            continue;
        }
        
        if (X <= st.top()) {
            int cnt = 0, last = cur;
            
            if (X < st.top()) { 
                cnt++; 
                st.pop(); 
            }

            while (!st.empty() && cur < N && S[cur] == st.top()) { 
                cnt += 2; 
                st.pop(); 
                last = cur++;
            }
            
            while (!st.empty()) {
                st.pop();
            }

            cur = last;
            res = max(res, cnt);
        }
    }

    cout << res << '\n';
    return 0;
}
