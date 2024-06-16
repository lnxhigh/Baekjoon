#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int TC;
const int MAX = 80;
char classRoom[MAX][MAX];

vector<pair<int,int>> graph[MAX][MAX];
bool visited[MAX][MAX];
pair<int,int> Left[MAX][MAX], Right[MAX][MAX];
pair<int,int> defaultMatch = { -1, -1 };

// 짝수 열 -> 홀수 열로 매칭을 시도하는데
// 뒤쪽을 확인하지 않으면 실제로는 불가능한데 매칭되는 경우가 생길 것 같다
pair<int,int> movement[7] = { 
    {0, 0}, {0, -1}, {0, +1}, {-1, -1}, {-1, +1}, {+1, -1}, {+1, +1}
};

bool dfs(const pair<int,int> &cur) {
    visited[cur.X][cur.Y] = true;
    
    for (const pair<int,int> &next : graph[cur.X][cur.Y]) {
        const pair<int,int> &p = Right[next.X][next.Y];
        bool check = false;
        if (p == defaultMatch) check = true;
        else if (!visited[p.X][p.Y] && dfs(p)) check = true;
        
        if (check) {
            Left[cur.X][cur.Y] = next;
            Right[next.X][next.Y] = cur;
            return true;
        }
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> TC;

    while (TC--) {
        // 입력 처리
        int R, C;
        cin >> R >> C;

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                cin >> classRoom[r][c];
            }
        }

        // 초기화
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                graph[r][c].clear();
                visited[r][c] = false;
                Left[r][c] = Right[r][c] = defaultMatch;
            }
        }

        // 앉을 수 있는 자리에 대해 X -> Y 로 이분 그래프 빌드
        // X: 짝수 열의 자리 -> Y: 홀수 열의 자리
        // 만약 컨닝 가능하다면 간선을 연결
        // 같은 열에서는 컨닝이 불가능하므로 이분 그래프가 생성된다
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c += 2) {
                if (classRoom[r][c] == 'x') continue;

                for (int k = 1; k <= 6; k++) {
                    int dr = movement[k].X, dc = movement[k].Y;
                    int nextR = r + dr, nextC = c + dc;
                    if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) continue;
                    if (classRoom[nextR][nextC] == 'x') continue;
                    graph[r][c].push_back({ nextR, nextC });
                }
            }
        }

        // 이분 그래프 최대 매칭 찾기
        int cnt = 0;

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (classRoom[r][c] == 'x') continue;
                if (Left[r][c] != defaultMatch) continue;

                fill(&visited[0][0], &visited[R-1][C-1] + 1, false);
                pair<int,int> start = { r, c };
                bool res = dfs(start);
                if (res) cnt++;
            }
        }

        // 결과 출력
        int total = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (classRoom[r][c] == '.') total++;
            }
        }

        int answer = total - cnt;
        cout << answer << '\n';
    }

    return 0;
}
