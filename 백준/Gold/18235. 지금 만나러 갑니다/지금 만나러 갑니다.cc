#include <bits/stdc++.h>
using namespace std;
const int MAX = 500005;

int N, A, B; 
int D[MAX];

int bfs() {
    queue<pair<int,int>> q;
    q.push({ A, 0 }); q.push({ B, 0 });

    while (!q.empty()) {
        auto [cur, day] = q.front();
        int jump = 1 << day;
        q.pop();

        for (int nxt : { cur + jump, cur - jump }) {
            if (nxt <= 0 || nxt > N) continue;

            // 스스로와 겹치지 않는다는 것을 증명 가능함
            if (D[nxt] == day + 1) return day + 1;
            
            D[nxt] = day + 1;
            q.push({ nxt, day + 1 });
        }
    }

    return -1;
}

int main() {
    cin >> N >> A >> B;
    int ans = bfs();
    cout << ans << '\n';
    return 0;
}
