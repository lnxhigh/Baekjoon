#include <bits/stdc++.h>
#define N_MAX 102
using namespace std;

int graph[N_MAX][N_MAX] = {0,};
int dist[N_MAX][N_MAX] = {0,};
int visited[N_MAX][N_MAX] = {0,};

void layout(vector<int> &rect, int graph[N_MAX][N_MAX]) {
    int l = rect[0], b = rect[1], r = rect[2], t = rect[3];
    for (int row = b; row <= t; row++) {
        for (int col = l; col <= r; col++) {
            graph[row][col] = 1;
        }   
    }
}

void find_edge(int graph[N_MAX][N_MAX]) {
    int dr[8] = {-1, +1, 0, 0, -1, -1, +1, +1};
    int dc[8] = {0, 0, -1, +1, -1, +1, -1, +1};
    for (int r = 0; r < N_MAX; r++) {
        for (int c = 0; c < N_MAX; c++) {
            if (graph[r][c] != 1) continue;
            for (int i = 0; i < 8; i++) {
                int rr = r + dr[i];
                int cc = c + dc[i];
                if (rr < 0 || rr >= N_MAX) continue;
                if (cc < 0 || cc >= N_MAX) continue;
                if (graph[rr][cc] == 0) graph[r][c]++;
            }
        }
    }
}

void bfs(int characterR, int characterC) {
    queue<pair<pair<int,int>, int>> q;
    q.push({{characterR, characterC}, 0});
    visited[characterR][characterC]++;
    
    int dr[4] = {-1, +1, 0, 0};
    int dc[4] = {0, 0, -1, +1};
    
    while (not q.empty()) {
        int curR = q.front().first.first;
        int curC = q.front().first.second;
        int depth = q.front().second;
        q.pop();
        
        dist[curR][curC] = depth;
        
        for (int i = 0; i < 4; i++) {
            int nextR = curR + dr[i];
            int nextC = curC + dc[i];
            if (nextR < 1 || nextR >= N_MAX) continue;
            if (nextC < 1 || nextC >= N_MAX) continue;
            if (visited[nextR][nextC]++) continue;
            if (graph[nextR][nextC] < 2) continue;
            
            q.push({{nextR, nextC}, depth + 1});
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    const int N = rectangle.size();
    characterX *= 2; characterY *= 2;
    itemX *= 2; itemY *= 2;
    
    for (vector<int> rect : rectangle) {
        for (int i = 0; i < 4; i++) {
            rect[i] *= 2;
        }
        layout(rect, graph);
    }
    
    find_edge(graph);
    bfs(characterY, characterX);
    
    int answer = dist[itemY][itemX] / 2;
    return answer;
}