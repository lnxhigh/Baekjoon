#include <bits/stdc++.h>
#define N_MAX 1000001
using namespace std;

int N;
int A[N_MAX];
int NGF[N_MAX];
int F[N_MAX] = {0,};
stack<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        F[A[i]]++;
        NGF[i] = -1;
    }
    for (int i = 0; i < N; i++) {
        while (!st.empty() && F[A[st.top()]] < F[A[i]]) {
            NGF[st.top()] = A[i];
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < N; i++) {
        cout << NGF[i] << ' ';
    }
    
    return 0;
}
