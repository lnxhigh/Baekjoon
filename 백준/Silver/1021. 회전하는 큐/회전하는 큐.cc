#include <bits/stdc++.h>
using namespace std;

int N, M;
const int MAX = 50;
int X[MAX];

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> X[i];
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    int res = 0;
    for (int i = 0; i < M; i++) {
        int cnt = 0;

        int s = q.size();
        for (int k = 0; k < s; k++) {
            if (q.front() == X[i]) {
                break;
            }
            
            int front = q.front();
            q.pop();
            q.push(front);

            cnt++;
        }

        res += min(cnt, s - cnt);
        q.pop();
    }

    cout << res << '\n';
    return 0;
}
