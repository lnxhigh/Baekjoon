#include <bits/stdc++.h>
#define V_MAX 100001
using namespace std;

int T;

vector<int> graph[V_MAX];
int visitTime = 0;
int visited[V_MAX];
bool finished[V_MAX];
stack<int> st;
vector<vector<int>> SCC;

int group[V_MAX];
int inDegree[V_MAX];

void init() {
    for (int i = 0; i < V_MAX; i++) graph[i].clear();
    visitTime = 0;
    fill(visited, visited + V_MAX, 0);
    fill(finished, finished + V_MAX, false);
    SCC.clear();

    fill(group, group + V_MAX, 0);
    fill(inDegree, inDegree + V_MAX, 0);
}

void input(int &V, int &E, vector<int> graph[V_MAX]) {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
    }
}

int dfs(int cur) {
    visited[cur] = ++visitTime;
    
    int res = visited[cur];
    st.push(cur);
    
    for (int next : graph[cur]) {
        if (!visited[next]) res = min(res, dfs(next));
        else if (!finished[next]) res = min(res, visited[next]);
    }

    if (res == visited[cur]) {
        vector<int> scc;
        while (true) {
            int top = st.top();
            scc.push_back(top);
            st.pop();
            finished[top] = true;
            if (top == cur) break;
        }

        SCC.push_back(scc);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        int V, E;

        // 초기화 및 입력
        init();
        input(V, E, graph);

        // SCC 추출
        for (int i = 0; i < V; i++) {
            if (!visited[i]) dfs(i);
        }

        // SCC 의 그룹 번호 표시
        int s = SCC.size();
        for (int i = 0; i < s; i++) {
            for (int k : SCC[i]) {
                group[k] = i;
            }
        }

        // 각 그룹의 전입 차수 기록
        for (int cur = 0; cur < V; cur++) {
            for (int next : graph[cur]) {
                if (group[cur] == group[next]) continue;
                inDegree[group[next]]++;
            }
        }

        // 전입 차수가 0이 되는 그룹 개수 세기
        vector<int> zeroDegree;
        for (int g = 0; g < s; g++) {
            if (inDegree[g] == 0) zeroDegree.push_back(g);
        }

        // 전입 차수가 0인 그룹이 2개 이상이면 도달 못하는 구역이 존재
        if (zeroDegree.size() > 1) {
            cout << "Confused" << '\n';
        }

        // 전입 차수가 0인 그룹이 1개라면 해당 그룹의 모든 원소를 출력
        else {
            int z = zeroDegree[0];
            for (int i = 0; i < V; i++) {
                if (group[i] == z) cout << i << '\n';
            }
        }
        cout << '\n';
    }

    return 0;
}
