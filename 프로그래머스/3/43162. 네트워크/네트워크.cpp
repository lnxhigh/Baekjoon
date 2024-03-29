#include <bits/stdc++.h>
#define N_MAX 200

using namespace std;

int component = 0;
int visited[N_MAX] = {0,};

int solution(int N, vector<vector<int>> computers) {
    for (int i = 0; i < N; i++) {
        if (visited[i]++) continue;
        component++;
        
        queue<int> q;
        q.push(i);
        
        while (not q.empty()) {
            int cur = q.front();
            q.pop();
            
            for (int next = 0; next < N; next++) {
                if (!computers[cur][next]) continue;
                if (visited[next]++) continue;
                q.push(next);
            }
        }
    }
    
    return component;
}