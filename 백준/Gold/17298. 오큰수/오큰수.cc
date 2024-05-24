#include <bits/stdc++.h>
#define N_MAX 1000001
using namespace std;

int N;
int A[N_MAX];
int NGE[N_MAX];
stack<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        NGE[i] = -1;
    }
    for (int i = 0; i < N; i++) {
        while (!st.empty() && A[st.top()] < A[i]) {
            NGE[st.top()] = A[i];
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < N; i++) {
        cout << NGE[i] << ' ';
    }
    cout << '\n';
    return 0;
}
