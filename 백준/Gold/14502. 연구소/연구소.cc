#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
using xy = pair<int,int>;

int R, C;
int map[10][10];
enum { FREE, WALL, VIRUS };
vector<xy> virus_loc, wall_loc;
int answer = 0;

void init(vector<xy> &virus_loc) {
    cin >> R >> C;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> map[r][c];
            if (map[r][c] == VIRUS) virus_loc.push_back({r,c});
        }
    }
}

void spread(int map[10][10], vector<xy> virus_loc) {
    queue<xy> q;
    int visited[10][10] = {0,};
    for (xy virus : virus_loc) {
        q.push(virus);
        visited[virus.first][virus.second]++;
    }

    while (not q.empty()) {
        xy cur = q.front();
        q.pop();

        xy moves[4] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
        for (xy move : moves) {
            xy next = { cur.first + move.first, cur.second + move.second };
            int x = next.first, y = next.second;
            if (x < 0 or x >= R) continue;
            if (y < 0 or y >= C) continue;
            if (visited[x][y]++) continue;
            if (map[x][y] != FREE) continue;

            q.push({x,y});
            map[x][y] = VIRUS;
        }
    }
}

int count_safety_zone(int map[10][10]) {
    int cnt = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (map[r][c] == 0) cnt++;
        }
    }
    return cnt;
}

void search(vector<xy> &wall_loc) {
    if (wall_loc.size() == 3) {
        int map_simulation[10][10];
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                map_simulation[r][c] = map[r][c];
            }
        }
        for (xy wall : wall_loc) {
            map_simulation[wall.first][wall.second] = WALL;
        }

        spread(map_simulation, virus_loc);
        int cnt = count_safety_zone(map_simulation);
        if (cnt > answer) answer = cnt;
        
        return;
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (map[r][c] != 0) continue;

            bool is_duplicated = false;
            for (xy wall : wall_loc) {
                if (wall.first == r and wall.second == c) {
                    is_duplicated = true;
                }
            }
            if (not is_duplicated) {
                wall_loc.push_back({r,c});
                search(wall_loc);
                wall_loc.pop_back();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    init(virus_loc);   
    search(wall_loc);
    cout << answer << '\n';
    
    return 0;
}