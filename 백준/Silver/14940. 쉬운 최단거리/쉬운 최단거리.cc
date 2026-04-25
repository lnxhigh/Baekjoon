#include <iostream>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int,int> xy;

int graph[1000][1000] = {0,};
bool visited[1000][1000] = {false,};
int dist[1000][1000] = {0,};

int N, M;
xy start;
xy movement[4] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
queue<xy> location;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    xy start;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 2) start = {i,j};
            else if (graph[i][j] == 1) dist[i][j] = -1;
            else dist[i][j] = 0;
        }
    }
    
    int level = 0;
    int cnt = 0, cur = 0, next = 1;

    int x = start.first;
    int y = start.second;
    
    graph[x][y] = level;
    visited[x][y] = true;
    dist[x][y] = 0;

    location.push(start);
    cur = next; 
    next = 0;
    level++;

    while (not location.empty()) {
        xy s = location.front();
        location.pop();
        cnt++;

        for (int i = 0; i < 4; i++) {
            xy move = movement[i];
            x = s.first + move.first;
            y = s.second + move.second;

            if ((not (x >= 0 and x < N)) or (not (y >= 0 and y < M))) continue;
            if (visited[x][y]) continue;
            if (graph[x][y] == 0) {
                visited[x][y] = true;
                continue;
            }
            
            visited[x][y] = true;
            location.push({x,y});
            dist[x][y] = level;
            next++;
        }

        if (cnt == cur) {
            cnt = 0;
            level++;
            cur = next;
            next = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}