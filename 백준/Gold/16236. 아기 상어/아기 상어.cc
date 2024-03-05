#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int N;
int state[20][20];

void bfs(int state[20][20], int dist[20][20], int size_shark, pair<int,int> loc_shark) {
    int visited[20][20] = {0,};

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            dist[r][c] = N*N+1;
        }
    }

    queue<pair<pair<int,int>,int>> q;
    q.push({loc_shark, 0});
    visited[loc_shark.first][loc_shark.second] = 1;

    while (not q.empty()) {
        pair<int,int> cur = q.front().first;
        int depth = q.front().second;
        q.pop();
        dist[cur.first][cur.second] = depth;

        pair<int,int> moves[4] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
        for (pair<int,int> move : moves) {
            pair<int,int> next = { cur.first + move.first, cur.second + move.second };
            int x = next.first, y = next.second;
            if (x < 0 or x >= N) continue;
            if (y < 0 or y >= N) continue;
            if (visited[x][y]++) continue;

            if (state[x][y] > size_shark) continue;
            q.push({next, depth+1});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 0;
    bool help = false;
    int size_shark = 2;
    int size_cnt = 0;
    pair<int,int> loc_shark;

    // Init
    cin >> N;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> state[r][c];
            if (state[r][c] == 9) loc_shark = {r,c};
        }
    }

    // Move and Eat
    while (not help) {
        vector<pair<int,int>> fish;
        vector<pair<int,int>> closest_fish;

        // Search fish the shark can eat
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {        
                if (state[r][c] == 0) continue;
                if (state[r][c] == 9) continue;
                if (state[r][c] < size_shark) fish.push_back({r,c});
            }
        }

        if (fish.empty()) help = true;
        if (help) break;

        // Calculate the distance to fish the shark can eat
        int dist[20][20];
        bfs(state, dist, size_shark, loc_shark);

        // Find the closest fish
        int min_dist = N*N;
        for (pair<int,int> loc_fish : fish) {
            int x = loc_fish.first, y = loc_fish.second;
            if (dist[x][y] < min_dist) min_dist = dist[x][y];
        }
        for (pair<int,int> loc_fish : fish) {
            int x = loc_fish.first, y = loc_fish.second;
            if (min_dist == dist[x][y]) closest_fish.push_back(loc_fish);
        }
        if (closest_fish.empty()) help = true;
        if (help) break;
        sort(closest_fish.begin(), closest_fish.end());
        
        // Update the state
        pair<int,int> loc_shark_next = *closest_fish.begin();
        int x = loc_shark_next.first, y = loc_shark_next.second;
        t += dist[x][y];
        size_cnt++;
        if (size_cnt == size_shark) {
            size_cnt = 0;
            size_shark++;
        }

        state[loc_shark.first][loc_shark.second] = 0;
        state[x][y] = 9;
        loc_shark = loc_shark_next;
    }

    cout << t << '\n';

    return 0;
}