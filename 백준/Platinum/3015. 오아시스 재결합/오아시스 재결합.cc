#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

int N;
const int N_MAX = 500000;
int A[N_MAX];
ll res = 0LL;

stack<pair<int,int>> st;
vector<pair<int,int>> H;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 개수 압축
    int curH = A[0];
    int cnt = 0;
    for (int i = 1; i < N; i++) {
        if (curH != A[i]) {
            H.push_back({ curH, ++cnt });
            cnt = 0;
            curH = A[i];
        }
        else {
            cnt++;
        }
    }
    H.push_back({ curH, ++cnt });

    // 키가 같은 사람끼리 서로 볼 수 있는 쌍의 수
    for (const pair<int,int> &p : H) {
        int k = p.second;
        res += 1LL * k * (k-1) / 2;
    }

    // 내림차순 스택 이용
    int L = H.size();
    for (int i = 0; i < L; i++) {
        pair<int,int> cur = H[i];
        int V = H[i].second; // 개수 병합용

        while (!st.empty() && st.top().X <= H[i].X) {
            pair<int,int> next = st.top();
            st.pop();

            if (next.X == H[i].X) V += next.Y;
            int k = (next.X == H[i].X) ? H[i].Y : 1;
            res += 1LL * next.Y * k;
            cur = next;
        }

        // 앞사람과 쌍을 형성
        if (!st.empty()) { res += 1LL * H[i].Y; }
        st.push({ H[i].first, V });
    }
    
    cout << res << '\n';

    return 0;
}
