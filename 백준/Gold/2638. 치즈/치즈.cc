#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
using xy = pair<int,int>;

int H, W;
int paper[101][101] = {0,};
int n_cheese = 0;
vector<xy> start;

void input(int &H, int &W, int paper[101][101]) {
    cin >> H >> W;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cin >> paper[h][w];
        }
    }
}

void init(vector<xy> &start) {
    // initialize starting point
    for (int h = 0; h < H; h++) {
        start.push_back({h, 0  });
        start.push_back({h, W-1});
    }
    for (int w = 0; w < W; w++) {
        start.push_back({0, w});
        start.push_back({H-1, w});
    }

    // Count the number of cheese
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (paper[h][w] == 1) n_cheese++;
        }
    }
}

void bfs(vector<xy> &start) {
    int cheese[101][101] = {0,};
    int visited[101][101] = {0,};
    queue<pair<xy,int>> q;
    vector<xy> move = { {-1,0}, {+1,0}, {0,-1}, {0,+1} };

    for (xy k : start) {
        q.push({k,1});
        visited[k.first][k.second] = 1;
    }

    while (not q.empty()) {
        xy cur = q.front().first;
        int depth = q.front().second;
        q.pop();

        for (xy m : move) {
            xy next = { cur.first + m.first, cur.second + m.second };
            int x = next.first, y = next.second;
            if (x < 0 or x >= H) continue;
            if (y < 0 or y >= W) continue;
            if (visited[x][y] == 1) continue;

            if (paper[x][y] == 1) {
                cheese[x][y]++;
            }
            else {
                visited[x][y] = 1;
                q.push({next, depth+1});
            }
        }
    }

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (cheese[h][w] >= 2) {
                paper[h][w] = 0;
                n_cheese--;
            }
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    input(H, W, paper);
    init(start);

    int res = 0;
    while (n_cheese > 0) {
        res++;
        bfs(start);
    }
    cout << res;

    return 0;
}