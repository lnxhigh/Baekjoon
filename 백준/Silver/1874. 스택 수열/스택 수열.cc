#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int N;
int A[100000];

pair<string,bool> solve() {
    string ret;
    
    stack<int> st;
    int num_to_push = 1;

    for (int i = 0; i < N; i++) { 
        if (st.empty() || A[i] > st.top()) {   
            while (st.empty() || A[i] > st.top()) {
                st.push(num_to_push++);
                ret.push_back('+');
            }
        }

        if (st.top() != A[i]) {
            return { ret, false };
        }

        st.pop();
        ret.push_back('-');
    }

    return { ret, true };
}

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    auto [ result, flag ] = solve();
    if (!flag) cout << "NO" << "\n";
    else for (char c : result) cout << c << "\n";
    return 0;
}
