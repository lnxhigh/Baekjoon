#include <iostream>
#include <utility>
using namespace std;
using xy = pair<int,int>;

int N;
char graph[100][100];
char graph_colorBlind[100][100];
bool visited[100][100];
bool visited_colorBlind[100][100];
xy movement[4] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

void dfs(int x, int y, char (&graph)[100][100], bool (&visited)[100][100]) {
    char color = graph[x][y];

    for (xy move : movement) {
        int a = x + move.first;
        int b = y + move.second;
        if (not (a >= 0 and a < N)) continue;
        if (not (b >= 0 and b < N)) continue;
        if (visited[a][b]) continue;
        if (graph[a][b] != color) continue;

        visited[a][b] = true;
        dfs(a, b, graph, visited);
    }
    return;
}

int get_component(char (&graph)[100][100], bool (&visited)[100][100]) {
    int component = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (not visited[i][j]) {
                visited[i][j] = true;
                dfs(i, j, graph, visited);
                component++;
            }
        }
    }

    return component;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'B') graph_colorBlind[i][j] = 'B';
            else graph_colorBlind[i][j] = 'K';
        }
    }
    
    cout << get_component(graph, visited) << '\n';
    cout << get_component(graph_colorBlind, visited_colorBlind) << '\n';

    return 0;
}