#include <bits/stdc++.h>

using namespace std;

int robots[128][128]; // (r,c) 에 존재하는 로봇의 개수

int curr[128]; // i번째 로봇이 현재 있는 포인트
pair<int,int> now[128]; // i번째 로봇의 좌표

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int t = 0;
    int ans = 0;
    bool finish = false;
    
    int n = points.size();
    int m = routes.size();
    
    // Init
    
    for (int i = 0; i < m; i++) {
        vector<int> &route = routes[i];
        for (int j = 0; j < route.size(); j++) {
            route[j]--; // zero based index
        }
    }
    
    for (int i = 0; i < m; i++) {
        int x = curr[i];
        vector<int> &route = routes[i];
        vector<int> &point = points[route[x]];
        
        int r = point[0];
        int c = point[1];
        
        robots[r][c]++;
        now[i] = { r, c };
    }
    
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (robots[i][j] > 1) {
                ans++;
            }
        }
    }
    
    // Loop
    
    do {        
        // 각 로봇별 이동
        
        bool updated = false;
        
        for (int i = 0; i < m; i++) {
            
            int x = curr[i];
            int nxt = x + 1;
            vector<int> &route = routes[i];
            
            if (nxt >= route.size()) continue;
            
            auto [r, c] = now[i];
            vector<int> &there = points[route[nxt]];
            
            updated = true;
            
            // 이동
            
            int newR = r, newC = c;
            
            if (r != there[0]) {
                newR = r < there[0] ? r + 1 : r - 1;
            } else {
                newC = c < there[1] ? c + 1 : c - 1;
            }
            
            now[i] = { newR, newC };
            robots[r][c]--;
            robots[newR][newC]++;
   
            // 다음 지점으로 도착했으면 현재 로봇 위치 업데이트
            if (newR == there[0] && newC == there[1]) {
                curr[i]++;
            }
        }
        
        // 충돌 위험 체크
        
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                if (robots[i][j] > 1) {
                    ans++;
                }
            }
        }
        
        // 끝났으면 물류 센터를 벗어남
        
        for (int i = 0; i < m; i++) {
            int x = curr[i];
            int nxt = x + 1;
            vector<int> &route = routes[i];
            
            if (nxt < route.size()) continue;
                    
            auto [r, c] = now[i];
            robots[r][c]--;
            now[i] = { -1, -1 };
        }
        
        // finish 업데이트
        
        if (!updated) {
            finish = true;
        }
    } while (!finish);
    
    return ans;
}
