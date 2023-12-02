#include <iostream>
#include <utility>
#include <algorithm>
#include <iterator>
#include <queue>
#include <set>
#define N_MAX 1001
#define M_MAX 1001
#define INF 2147483647
using namespace std;
using xy = pair<int,int>;

struct Node {
    xy loc;
    int depth;
};

int N, M;
char Map[N_MAX][M_MAX] = {0,};
int distFromStart[N_MAX][M_MAX];
int distFromEnd[N_MAX][M_MAX];
set<xy> wallFromStart;
set<xy> wallFromEnd;

xy movement[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<Node> q;

xy operator+(xy left, xy right) {
    return { left.first + right.first, left.second + right.second };
}

bool isValid(xy move) {
    int x = move.first, y = move.second;
    if (x < 1 or x > N) return false;
    if (y < 1 or y > M) return false;
    return true;
}

void BFS(xy start, int dist[N_MAX][M_MAX], set<xy> &wall) {
    bool visited[N_MAX][M_MAX] = {false,};
    visited[start.first][start.second] = true;
    dist[start.first][start.second] = 1;

    q.push({start, 1});
    while (not q.empty()) {
        Node x = q.front();
        q.pop();

        for (xy move : movement) {
            xy k = x.loc + move;
            if (not isValid(k)) continue;
            if (visited[k.first][k.second]) continue;
            
            visited[k.first][k.second] = true;
            dist[k.first][k.second] = x.depth+1;
            if (Map[k.first][k.second] == '0') {
                q.push({k, x.depth+1});
            }
            else {
                wall.insert(k);
            }
        }

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        char row[M_MAX];
        cin >> row;
        for (int j = 1; j <= M; j++) {
            Map[i][j] = row[j-1];
        }
    }
    
    fill(&distFromStart[1][1], &distFromStart[N][M+1], INF);
    fill(&distFromEnd[1][1], &distFromEnd[N][M+1], INF);

    BFS({1, 1}, distFromStart, wallFromStart);
    BFS({N, M}, distFromEnd, wallFromEnd);

    set<xy> wall;

    set_intersection(
        wallFromStart.begin(), wallFromStart.end(), 
        wallFromEnd.begin(), wallFromEnd.end(),
        inserter(wall, wall.begin())
    );

    int ans = distFromStart[N][M];
    for (xy k : wall) {
        ans = min(ans, distFromStart[k.first][k.second] + distFromEnd[k.first][k.second] - 1);
    }

    if (ans == INF) ans = -1;
    cout << ans;

    return 0;
}