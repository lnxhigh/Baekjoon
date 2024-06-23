#include <bits/stdc++.h>
using namespace std;

int H, W;
const int MAX = 501;
int A[MAX];

stack<int> st;
int res = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> H >> W;
    for (int i = 0; i < W; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < W; i++) {
        int k = 0;
        while (!st.empty() && A[st.top()] < A[i]) {
            res += (i - st.top() - 1) * (A[st.top()] - k);
            k = A[st.top()];
            st.pop();
        }

        if (!st.empty()) {
            res += (i - st.top() - 1) * (A[i] - k);
        }
        st.push(i);
    }

    cout << res << '\n';
    return 0;
}
