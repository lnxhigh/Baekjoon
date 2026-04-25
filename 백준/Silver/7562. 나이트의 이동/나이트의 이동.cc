#include <iostream>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int,int> xy;

int board[300][300] = {0,};
bool visited[300][300] = {false,};
int T, I;
int x, y;
xy departure;
xy arrival;
xy movement[8] = { {1,2}, {-1,2}, {1,-2}, {-1,-2}, {2,1}, {-2,1}, {2,-1}, {-2,-1} };
queue<xy> location;

int bfs(int I, xy departure, xy arrival) {

    int level = 0;
    int cnt = 0, cur = 0, next = 1;

    int x = departure.first;
    int y = departure.second;
    
    board[x][y] = level;
    visited[x][y] = true;
    location.push(departure);
    cur = next; 
    next = 0;
    level++;

    while (not location.empty()) {
        xy start = location.front();
        location.pop();
        cnt++;

        for (int i = 0; i < 8; i++) {
            xy move = movement[i];
            x = start.first + move.first;
            y = start.second + move.second;

            if ((not (x >= 0 and x < I)) or (not (y >= 0 and y < I))) continue;
            if (visited[x][y]) continue;
            
            visited[x][y] = true;
            location.push({x,y});
            board[x][y] = level;
            next++;
        }

        if (cnt == cur) {
            cnt = 0;
            level++;
            cur = next;
            next = 0;
        }
    }
    
    return board[arrival.first][arrival.second];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> I;
        for (int r = 0; r < I; r++) {
            for (int c = 0; c < I; c++) {
                visited[r][c] = false;
            }
        }

        cin >> x >> y;
        xy departure = {x,y};
        
        cin >> x >> y;
        xy arrival = {x,y};
        
        cout << bfs(I, departure, arrival) << '\n';
    }
    
    return 0;
}