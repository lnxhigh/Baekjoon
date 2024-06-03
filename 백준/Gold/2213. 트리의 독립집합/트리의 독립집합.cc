#include <bits/stdc++.h>
#define N_MAX 10001
using namespace std;

int N;
int W[N_MAX];
vector<int> graph[N_MAX];

// D[k][i] 설명
// k == 0 이면 노드 i 를 포함하지 않는 상태. k == 1 이면 i 를 포함하는 상태.
// i 는 i 를 루트로 하는 서브 트리에 대해 최대 독립집합의 크기를 의미
int D[2][N_MAX];
bool visited[N_MAX];

// P 는 최단거리 역추적을 위함
vector<pair<int,int>> P[2][N_MAX];

// Leaf 에서 시작해서 DP 를 돌리는 함수
void dfs(int parent) {
    for (int child : graph[parent]) {
        if (visited[child]) continue;
        visited[child] = true;
        dfs(child); // Leaf 부터 시작하도록 강제

        int k = D[0][child] > D[1][child] ? 0 : 1;
        D[0][parent] += D[k][child];
        D[1][parent] += D[0][child];

        P[0][parent].push_back({ k, child });
        P[1][parent].push_back({ 0, child });
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> W[i];
        D[1][i] += W[i];
    }
    for (int i = 0; i < N-1; i++) {
        int U, V;
        cin >> U >> V;
        graph[U].push_back(V);
        graph[V].push_back(U);
    }

    // Root 는 편의를 위해 설정한 것으로 1이 아니어도 상관 없다
    int root = 1;
    visited[root] = true;
    dfs(root);
    
    // 최대 독립집합의 크기 출력
    int k = D[0][root] > D[1][root] ? 0 : 1;
    int size = D[k][root];
    cout << size << '\n';

    // 최대 독립집합에 속하는 정점 출력
    vector<int> res;
    fill(visited, visited + N_MAX, false);
    queue<pair<int,int>> q;

    q.push({ k, root });
    visited[root] = true;

    while (!q.empty()) {
        int choice = q.front().first;
        int parent = q.front().second;
        q.pop();

        if (choice == 1) res.push_back(parent);

        for (const pair<int,int> &p : P[choice][parent]) {
            int child = p.second;
            if (visited[child]) continue;
            visited[child] = true;
            q.push(p);
        }
    }

    sort(res.begin(), res.end());
    for (int i : res) { cout << i << ' '; }
    cout << '\n';

    return 0;
}
