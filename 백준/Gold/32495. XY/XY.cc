#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int len(int x, int y) {
    int g = gcd(x, y);
    return x + y - g - 1;
}

vector<int> generate(int x, int y) {

    // Build DAG
    int N = len(x, y); ++N;
    vector<vector<int>> graph(N);
    vector<int> inDegree(N);

    for (int i = 0; i < x; i++) {
        for (int j = i; j + x < N; j += x) {
            graph[j].push_back(j + x);
            inDegree[j + x]++;
        }
    }

    for (int i = 0; i < y; i++) {
        for (int j = i; j + y < N; j += y) {
            graph[j + y].push_back(j);
            inDegree[j]++;
        }
    }

    // Topological Sort
    int t = 0;
    queue<int> q;
    vector<int> sum(N);

    for (int i = 0; i < N; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        sum[cur] = t++;

        q.pop();
        for (int next : graph[cur]) {
            if (--inDegree[next] == 0) q.push(next);
        }
    }

    // Difference
    vector<int> res(N - 1);
    for (int i = 0; i < N - 1; i++) {
        res[i] = sum[i+1] - sum[i];
    }

    return res;
}

int main() {
    FastIO
    int Q; cin >> Q;

    Q--;
    int x, y; cin >> x >> y;
    cout << len(x, y) << ' ';
    vector<int> seq = generate(x, y);

    while (Q--) {
        int x, y; cin >> x >> y;
        cout << len(x, y) << ' ';
    }
    cout << '\n';

    for (int k : seq) {
        cout << k << ' ';
    }
    cout << '\n';
    return 0;
}
