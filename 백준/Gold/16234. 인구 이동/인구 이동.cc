#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using xy = pair<int,int>;
int N, L, R;
int world[51][51];

void input(int &N, int world[51][51]) {
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> world[i][j];
        }
    }
}

void print(int world[51][51]) {
    cout << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << world[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int bfs(int world[51][51]) {
    queue<xy> q;
    int visited[51][51] = {0,};
    int component = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) continue;
            component++;
            
            q.push({i,j});
            visited[i][j] = 1;

            vector<pair<xy,int>> population;
            population.push_back({ {i,j}, world[i][j] });

            while (not q.empty()) {
                xy front = q.front();
                q.pop();

                vector<xy> move = {{-1,0},{1,0},{0,-1},{0,1}};
                for (xy m : move) {
                    int x = front.first + m.first;
                    int y = front.second + m.second;
                    if (x < 0 or x >= N) continue;
                    if (y < 0 or y >= N) continue;
                    if (visited[x][y]) continue;
                    
                    int value = abs(world[front.first][front.second] - world[x][y]);
                    if (value >= L and value <= R) {
                        q.push({x,y});
                        visited[x][y] = 1;
                        population.push_back({{x,y}, world[x][y]});
                    }
                }
            }

            int sum = 0, cnt = 0;
            for (pair<xy,int> country : population) {
                sum += country.second;
                cnt += 1;
            }
            int average = sum / cnt;
            
            for (pair<xy,int> country : population) {
                xy loc = country.first;
                world[loc.first][loc.second] = average;
            }
        }
    }

    return component;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int day = 0;
    input(N, world);
    while (true) {
        int component = bfs(world);
        if (component == N*N) break;
        day++;
    }

    cout << day << '\n';
    return 0;
}
