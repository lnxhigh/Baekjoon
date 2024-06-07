#include <bits/stdc++.h>
#define N_MAX 100001
using namespace std;

int T;
vector<int> graph[N_MAX];

int visitTime = 0;
int visited[N_MAX];
bool finished[N_MAX];
stack<int> st;

int group[N_MAX];
int inDegree[N_MAX];

vector<vector<int>> SCC;

void init() {
    for (int i = 0; i < N_MAX; i++) { graph[i].clear(); }

    visitTime = 0;
    fill(visited, visited + N_MAX, false);
    fill(finished, finished + N_MAX, false);
    
    fill(group, group + N_MAX, 0);
    fill(inDegree, inDegree + N_MAX, 0);
    
    SCC.clear();
}

void input(int &N, int &M, vector<int> graph[N_MAX]) {
    for (int i = 0; i < N_MAX; i++) { graph[i].clear(); }
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
}

int dfs(int start) {
    visited[start] = ++visitTime;
    int res = visited[start];
    st.push(start);

    for (int next : graph[start]) {
        if (!visited[next]) res = min(res, dfs(next));
        else if (!finished[next]) res = min(res, visited[next]);
    }

    if (res == visited[start]) {
        vector<int> scc;
        while (true) {
            int top = st.top();
            scc.push_back(top);
            st.pop();
            finished[top] = true;
            if (top == start) break;
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
        int N, M;

        // 초기화 및 입력
        init();
        input(N, M, graph);

        // SCC 추출
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) dfs(i);
        }

        // 노드 k가 속한 SCC 그룹 표시
        int s = SCC.size();
        for (int i = 0; i < s; i++) {
            for (int k : SCC[i]) {
                group[k] = i;
            }
        }

        // SCC 별로 전입 차수 기록
        for (int cur = 1; cur <= N; cur++) {
            for (int next : graph[cur]) {
                if (group[cur] == group[next]) continue;
                inDegree[group[next]]++;
            }
        }

        // 전입 차수가 0인 컴포넌트 선택
        int answer = 0;
        for (int g = 0; g < s; g++) {
            if (inDegree[g] == 0) answer++;
        }
        cout << answer << '\n';
    }

    return 0;
}
