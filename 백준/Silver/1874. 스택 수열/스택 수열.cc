#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 1 << 17;
int X[MAX];

stack<int> st;
vector<char> res;
bool isImpossible = false;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) { cin >> X[i]; }

    int cur = 1;
    for (int i = 1; i <= N; i++) {
        for (int k = cur; k <= X[i]; k++) { st.push(k); res.push_back('+'); }
        if (st.top() != X[i]) { isImpossible = true; break; }
        st.pop(); res.push_back('-');
        cur = max(cur, X[i] + 1);
    }

    if (isImpossible) cout << "NO" << '\n';
    else { for (char c : res) cout << c << '\n'; }

    return 0;
}
