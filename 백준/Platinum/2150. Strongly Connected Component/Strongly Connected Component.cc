#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define V_MAX 10001
using namespace std;

int V, E;
vector<int> graph[V_MAX];

stack<int> st;
int visitTime = 0;
int visited[V_MAX];
bool finished[V_MAX];

vector<vector<int>> SCC;

int DFS(int start) {
    // visitTime == 0 이면 아직 방문하지 않은 것임
    // visitTime 이 가장 작은 노드가 가장 위 조상이 된다
    visited[start] = ++visitTime;
    st.push(start);

    int res = visited[start];
    for (int next : graph[start]) {
        if (!visited[next]) res = min(res, DFS(next));
        else if (!finished[next]) res = min(res, visited[next]);

        // finished 인 경우는 고려하지 않는 이유:
        // 이미 SCC 가 된 노드들은 현재 노드로 오는 것이 애초에 불가능했던 노드들이다
    }

    // res 는 자신이 속한 SCC 그룹의 방문 시간의 최솟값을 의미
    // 만약 자신의 조상으로 갈 수 있는 경로가 존재한다면
    // res < visited[start] 가 될 것이다

    // 자신의 조상으로 갈 수 있는 경로가 존재하지 않는다면
    // 그때부터 SCC를 추출하며 finished = true 로 만든다
    // finished 는 스택에 존재하는지 여부를 지시한다

    if (res == visited[start]) {
        vector<int> scc;
        while (true) {
            int top = st.top();
            finished[top] = true;
            scc.push_back(top); 
            st.pop();
            
            if (top == start) break;
        }

        SCC.push_back(scc);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
    }

    for (int i = 1; i <= V; i++) {
        if (visited[i]) continue;
        DFS(i);
    }

    for (vector<int> &scc : SCC) sort(all(scc));
    sort(all(SCC), [] (vector<int> &left, vector<int> &right) {
        return left[0] < right[0];
    });

    cout << SCC.size() << '\n';
    for (vector<int> &scc : SCC) {
        for (int i : scc) cout << i << ' ';
        cout << -1 << '\n';
    }

    return 0;
}
