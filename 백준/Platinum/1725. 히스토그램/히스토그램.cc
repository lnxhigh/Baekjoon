#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 100001;
int H[N_MAX];

struct Rect { int W, H; };
stack<Rect> st;
int area = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) { cin >> H[i]; }
    H[N++] = -1;

    for (int i = 0; i < N; i++) {
        int k = 0;
        while (!st.empty() && st.top().H >= H[i]) {
            int w = st.top().W + k;
            int h = st.top().H;
            area = max(area, w * h);
            k += st.top().W;
            st.pop();
        }

        st.push({ ++k, H[i] });
    }

    cout << area << '\n';
    return 0;
}
