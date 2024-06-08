#include <bits/stdc++.h>
#define V_MAX 500001
using namespace std;

int V, E;
vector<int> graph[V_MAX];
int Money[V_MAX];
int S, P;
vector<int> restaurant;

int visitTime = 0;
int visited[V_MAX];
int finished[V_MAX];
stack<int> st;
vector<vector<int>> SCC;

int group[V_MAX];
vector<int> sccGraph[V_MAX];
int inDegree[V_MAX];
int cost[V_MAX];
int total[V_MAX];

void input() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }
    for (int i = 1; i <= V; i++) {
        cin >> Money[i];
    }
    cin >> S >> P;

    for (int i = 0; i < P; i++) {
        int L;
        cin >> L;
        restaurant.push_back(L);
    }
}

int dfs(int cur) {
    visited[cur] = ++visitTime;
    st.push(cur);
    int res = visited[cur];

    for (int next : graph[cur]) {
        if (!visited[next]) res = min(res, dfs(next));
        else if (!finished[next]) res = min(res, visited[next]);
    }

    if (res == visited[cur]) {
        vector<int> scc;
        while (true) {
            int top = st.top();
            st.pop();
            finished[top] = true;
            scc.push_back(top);

            if (top == cur) break;
        }
        SCC.push_back(scc);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // Input
    input();    

    // SCC 추출
    for (int i = 1; i <= V; i++) {
        if (!visited[i]) dfs(i);
    }

    // SCC 를 그룹으로 묶어 새로운 그래프 생성
    int s = SCC.size();
    for (int i = 0; i < s; i++) {
        for (int k : SCC[i]) {
            cost[i] += Money[k];
            group[k] = i;
        }
    }

    for (int cur = 1; cur <= V; cur++) {
        for (int next : graph[cur]) {
            if (group[cur] == group[next]) continue;
            inDegree[group[next]]++;
            sccGraph[group[cur]].push_back(group[next]);
        }
    }

    // 위상 정렬을 수행
    queue<int> q;
    for (int i = 0; i < s; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    vector<int> topo;
    for (int i = 0; i < s; i++) {
        int cur = q.front();
        topo.push_back(cur);
        q.pop();

        for (int next : sccGraph[cur]) {
            if (--inDegree[next] == 0) q.push(next);
        }
    }

    // 위상 정렬된 순서를 따라 source에서 sink까지의 최대 비용을 계산
    fill(total, total + V_MAX, -1);
    total[group[S]] = cost[group[S]];
    for (int cur : topo) {
        if (total[cur] < 0) continue;
        for (int next : sccGraph[cur]) {
            total[next] = max(total[next], total[cur] + cost[next]);
        }
    }

    // 모든 레스토랑에 대해서 최대 비용을 계산
    int answer = 0;
    for (int k : restaurant) {
        answer = max(answer, total[group[k]]);
    }

    cout << answer << '\n';

    return 0;
}
