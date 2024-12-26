#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 80005;

int N;
int H[MAX], X[MAX];

int main() {
    FastIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    H[N] = INT_MAX;

    stack<int> st;
    for (int i = 0; i <= N; i++) {
        while (!st.empty() && H[st.top()] <= H[i]) {
            X[st.top()] += i - st.top() - 1;
            st.pop();
        }
        st.push(i);
    }
    
    long long cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += (long long) X[i];
    }
    cout << cnt << '\n';

    return 0;
}
