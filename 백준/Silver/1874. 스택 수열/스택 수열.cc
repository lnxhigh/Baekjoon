#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N;
vector<int> A;

pair<bool,string> solve() {
    stack<int> st;
    string ret;
    int k = 0, i = 1;

    while (true) {
        if (!st.empty() && st.top() == A[k]) {
            k++;
            st.pop();
            ret.push_back('-');
        }

        if (k >= N) break;

        if (st.empty() || st.top() < A[k]) {
            st.push(i++);
            ret.push_back('+');
        }
        else if (st.top() > A[k]) {
            st.pop();
            if (st.empty() || st.top() != A[k]) {
                return { false, ret };
            }
        }
    }

    return { true, ret };
}

int main() {
    FastIO
    cin >> N;
    A.resize(N);
    for (int &X : A) cin >> X;
    
    auto [flag, op] = solve();
    if (flag) {
        for (char c : op) cout << c << '\n';
    }
    else {
        cout << "NO" << '\n';
    }
    return 0;
}
