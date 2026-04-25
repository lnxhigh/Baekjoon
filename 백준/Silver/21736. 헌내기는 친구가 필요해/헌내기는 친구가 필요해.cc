#include <iostream>
#include <utility>
#include <queue>
#define MAX 601
using namespace std;
using xy = pair<int,int>;

int N, M;
char graph[MAX][MAX];
bool visited[MAX][MAX] = {false,};
xy movement[4] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
queue<xy> location;

xy operator+ (xy p1, xy p2) {
    return {p1.first + p2.first, p1.second + p2.second};
}

bool isValidLocation(xy loc) {
    int i = loc.first;
    int j = loc.second;

    if (not (i >= 0 and i < N)) return false;
    if (not (j >= 0 and j < M)) return false;
    if (visited[i][j]) return false;
    
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> graph[i];
    }

    bool findI = false;
    for (int i = 0; i < N; i++) {
        if (findI) break;
        for (int j = 0; j < M; j++) {
            if (findI) break;
            if (graph[i][j] == 'I') {
                location.push({i,j});
                visited[i][j] = true;
                findI = true;
            }
        }
    }
    
    int cnt = 0;
    while (not location.empty()) {
        xy loc = location.front();
        location.pop();
        if (graph[loc.first][loc.second] == 'P') {
            cnt++;
        }

        for (xy m : movement) {
            if (isValidLocation(loc + m)) {
                int i = loc.first + m.first;
                int j = loc.second + m.second;
                visited[i][j] = true;
                if (graph[i][j] != 'X') location.push(loc + m);
            }
        }
    }

    if (not cnt) cout << "TT";
    else cout << cnt;
    return 0;   
}