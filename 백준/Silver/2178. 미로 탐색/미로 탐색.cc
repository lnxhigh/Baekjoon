#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int N, M;
int maze[101][101];
int dist[101][101];
bool visited[101][101] = {false,};
queue<pair<pair<int,int>,int>> q;

void input(int &N, int &M, int maze[101][101]) {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        char line[101];
        cin >> line;
        for (int j = 0; j < M; j++) {
            maze[i][j] = line[j] - '0';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    input(N, M, maze);

    q.push({{0, 0}, 1});
    visited[0][0] = true;
    dist[0][0] = 1;

    pair<int,int> move[4] = { {-1,0}, {+1,0}, {0,-1}, {0,+1} };
    while (not q.empty()) {
        pair<pair<int,int>,int> info = q.front();
        q.pop();
        
        pair<int,int> x = info.first;
        int depth = info.second;

        for (pair<int,int> m : move) {
            int a = x.first + m.first;
            int b = x.second + m.second;

            if (a < 0 or a >= N) continue;
            if (b < 0 or b >= M) continue;

            if (visited[a][b]) continue;

            visited[a][b] = true;
            dist[a][b] = depth+1;

            if (maze[a][b] == 1) {
                q.push({{a, b}, depth+1});
            }
        }
    }
    
    cout << dist[N-1][M-1] << '\n';

    return 0;
}