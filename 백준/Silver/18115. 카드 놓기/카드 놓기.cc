#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 20;

int main() {
    FastIO
    int N; cin >> N;
    
    int card = 0;
    stack<int> st;
    deque<int> dq;

    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        st.push(x);
    }

    while (!st.empty()) {
        card++;
        int x = st.top();
        st.pop();

        if (x == 1) {
            dq.push_front(card);
        }
        else if (x == 2) {
            int top = dq.front();
            dq.pop_front();
            dq.push_front(card);
            dq.push_front(top);
        }
        else if (x == 3) {
            dq.push_back(card);
        }
    }

    while (!dq.empty()) {
        int card = dq.front();
        dq.pop_front();
        cout << card << ' ';
    }
    cout << '\n';

    return 0;
}
