#include <bits/stdc++.h>
using namespace std;

int N;
int D[369];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int S, E; cin >> S >> E;
        for (int day = S; day <= E; day++) D[day]++;
    }

    int area = 0;
    stack<int> st;

    for (int day = 1; day <= 366; day++) {
        if (D[day]) {
            st.push(day);
        }
        else {
            int w = st.size(), h = 0;
            while (!st.empty()) h = max(h, D[st.top()]), st.pop(); 
            area += w * h;
        }
    }

    cout << area << '\n';
    return 0;
}
