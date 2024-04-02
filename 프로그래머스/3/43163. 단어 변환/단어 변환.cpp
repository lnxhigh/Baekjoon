#include <bits/stdc++.h>
using namespace std;

map<string,int> visited;

bool interchangable(string from, string to, int N) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (from[i] == to[i]) cnt++;
    }
    return cnt == N-1;    
}

int solution(string begin, string target, vector<string> words) {
    const int N = begin.size();
    int answer = 0;
    queue<pair<string,int>> q;
    q.push({begin, 0});
    visited[begin]++;
    
    while (not q.empty()) {
        string curWord = q.front().first;
        cout << curWord << ' ';
        int depth = q.front().second;
        q.pop();
        
        if (curWord == target) {
            answer = depth;
            break;
        }
        
        for (string nextWord : words) {
            if (visited[nextWord]) continue;
            if (not interchangable(curWord, nextWord, N)) continue;
            q.push({nextWord, depth+1});
            visited[nextWord]++;
        }
    }
    
    return answer;
}