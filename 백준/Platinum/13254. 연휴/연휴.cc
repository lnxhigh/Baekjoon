#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 1 << 6;
int N, M; 
vector<int> tree[MAX];
multiset<int> family;

// D[k]: 자신의 parent 로 가는 간선을 제거했을 때
// 그 그룹에 속한 도시와 가족의 수를 저장

pair<int,int> D[MAX];
bool visited[MAX];

pair<int,int> dfs(int cur) {
    int tot = 1; // 도시의 수
    int cnt = family.count(cur); // 가족의 수
    visited[cur] = true;
    
    for (int next : tree[cur]) {
        if (visited[next]) continue;
        auto [ x, y ] = dfs(next);
        tot += x; cnt += y;
    }

    return D[cur] = { tot, cnt };
}

int main() {
    FastIO
    cout << setprecision(16);
    cin >> N >> M;

    for (int i = 0; i < N - 1; i++) {
        int x, y; cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        family.insert(x);
    }

    dfs(0);

    double res = 0;

    for (int i = 1; i < N; i++) {
        auto [ x, a ] = D[i];
        int y = N - x, b = M - a;

        // 중복순열
        double p = a * log(y) + b * log(x) - M * log(N - 1);
        res += exp(p);
    }

    cout << res << '\n';
    return 0;
}
