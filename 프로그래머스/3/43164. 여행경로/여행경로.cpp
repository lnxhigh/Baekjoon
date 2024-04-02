#include <bits/stdc++.h>
using namespace std;

int N = 0, cnt = 0;
map<string, vector<string>> graph;
map<pair<string,string>, int> visited;
vector<vector<string>> paths;
vector<string> path;

void dfs(string start, vector<string> &path) {
    if (cnt == N) {
        paths.push_back(path);
        return;
    }
    
    for (string next : graph[start]) {
        pair<string,string> ticket = { start, next };
        if (visited[ticket] == 0) continue;
        
        cnt++;
        visited[ticket]--;
        path.push_back(next);
        dfs(next, path);
        cnt--;
        visited[ticket]++;
        path.pop_back();
    }
}

bool compare(vector<string> &left, vector<string> &right) {
    const int K = left.size();
    string s1 = "";
    string s2 = "";
    for (int i = 0; i < K; i++) {
        s1 += left[i];
        s2 += right[i];
    }
    return s1 < s2;
}

vector<string> solution(vector<vector<string>> tickets) {
    N = tickets.size();
    for (vector<string> ticket : tickets) {
        string from = ticket[0];
        string to = ticket[1];
        graph[from].push_back(to);
        visited[{from,to}]++;
    }
    
    string start = "ICN";
    path.push_back(start);
    dfs(start, path);
    
    sort(paths.begin(), paths.end(), compare);
    return *paths.begin();
}