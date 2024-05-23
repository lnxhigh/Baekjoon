#include <bits/stdc++.h>
#define N_MAX 501
using namespace std;

void printAnswer(int numCase, int numTrees) {
    string answer = "Case ";
    answer += to_string(numCase);
    answer += ": ";
    
    if (numTrees == 0) answer += "No trees.";
    else if (numTrees == 1) answer += "There is one tree.";
    else {
        answer += "A forest of ";
        answer += to_string(numTrees);
        answer += " trees.";
    }

    cout << answer << '\n';
}

bool isTree(vector<int> &vertex, vector<int> graph[N_MAX]) {
    int numVertices = vertex.size();
    int numEdges = 0;

    for (int v : vertex) {
        numEdges += graph[v].size();
    }
    numEdges /= 2;

    return numVertices == numEdges + 1;
}

int countTree(vector<int> graph[N_MAX], int V, int E) {
    int res = 0;
    int visit[N_MAX] = {0,};

    for (int i = 1; i <= V; i++) {
        if (visit[i]++) continue;

        vector<int> vertex;
        queue<int> q;
        q.push(i);
        while (not q.empty()) {
            int cur = q.front();
            q.pop();
            vertex.push_back(cur);
            for (int next : graph[cur]) {
                if (visit[next]++) continue;
                q.push(next);
            }
        }

        if (isTree(vertex, graph)) {
            res++;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int numCase = 0;
    while (true) {
        int V, E;
        cin >> V >> E;
        if (V == 0 && E == 0) break;

        numCase++;
        vector<int> graph[N_MAX];
        for (int i = 0; i < E; i++) {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        int numTrees = countTree(graph, V, E);
        printAnswer(numCase, numTrees);
    }

    return 0;
}
