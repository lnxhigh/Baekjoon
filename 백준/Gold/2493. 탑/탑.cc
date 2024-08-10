#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 1 << 19;
int H[N_MAX], R[N_MAX];
stack<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> H[i];

    for (int i = 0; i < N; i++) {
        while (!st.empty() && H[st.top()] < H[i]) st.pop();
        if (!st.empty()) R[i] = st.top() + 1;
        st.push(i);
    }

    for (int i = 0; i < N; i++) cout << R[i] << ' ';
    cout << '\n';
    return 0;
}
