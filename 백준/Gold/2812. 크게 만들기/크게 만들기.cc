#include <bits/stdc++.h>
using namespace std;

int N, K;
string S;
stack<char> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K;
    cin >> S;

    for (char letter : S) {
        while (!st.empty() && st.top() < letter) {
            if (K == 0) break;
            st.pop(); K--;
        }
        st.push(letter);
    }

    for (int i = 0; i < K; i++) st.pop();

    string check = "";
    while (!st.empty()) {
        check += st.top();
        st.pop();
    }

    reverse(check.begin(), check.end());
    cout << check << '\n';
    
    return 0;
}
