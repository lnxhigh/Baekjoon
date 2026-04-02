#include <bits/stdc++.h>

using namespace std;
const int MAX = 3125 * 2;

bool graph[MAX][MAX];
int limits[MAX][MAX];
int par[MAX * MAX];
map<int,int> x_map, y_map;

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

void init(const vector<vector<int>> &cities, const vector<vector<int>> &roads) {
    // compression
    vector<int> x, y;
    
    for (const vector<int> &city : cities) {
        int x0 = city[0], y0 = city[1];
        x.push_back(x0);
        y.push_back(y0);
    }
    
    for (const vector<int> &road : roads) {
        int x1 = road[0], y1 = road[1], x2 = road[2], y2 = road[3];
        vector<int> vec = { x1, y1, x2, y2, (x1 + x2) / 2, (y1 + y2) / 2 };
        
        for (int i = 0; i < 6; i++) {
            if (i % 2 == 0) x.push_back(vec[i]);
            else y.push_back(vec[i]);
        }
    }
    
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    x.erase(unique(x.begin(), x.end()), x.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    
    for (int i = 0; i < x.size(); i++) {
        x_map[x[i]] = i * 2;
    }
    for (int i = 0; i < y.size(); i++) {
        y_map[y[i]] = i * 2;
    }
    
    // graph
    
    for (const vector<int> &road : roads) {
        int x1 = x_map[road[0]], y1 = y_map[road[1]];
        int x2 = x_map[road[2]], y2 = y_map[road[3]];
        int xc = x_map[(road[0] + road[2]) / 2];
        int yc = y_map[(road[1] + road[3]) / 2];
        int limit = road[4];
        
        if (limits[xc][yc] == 0) limits[xc][yc] = limit;
        else limits[xc][yc] = min(limits[xc][yc], limit);
        
        if (x1 == x2) {
            for (int i = y1; i <= y2; i++) {
                graph[xc][i] = true;
            }
        } else if (y1 == y2) {
            for (int i = x1; i <= x2; i++) {
                graph[i][yc] = true;
            }
        }
    }
}

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    else if (x < y) swap(x, y);
    
    par[x] = y;
    return true;
}

vector<int> mst(const vector<vector<int>> &cities_raw) {
    vector<int> cities;
    vector<vector<int>> edges;
    
    int n = cities_raw.size();
    vector<bool> check(n);
    vector<int> result(n - 1);
    
    for (const vector<int> &city : cities_raw) {
        int x = x_map[city[0]];
        int y = y_map[city[1]];
        cities.push_back(x * MAX + y);
    }
    
    for (int i = 0; i < MAX * MAX; i++) {
        par[i] = i;
    }
    
    for (int x = 0; x < MAX; x++) {
        for (int y = 0; y < MAX; y++) {
            if (not graph[x][y]) continue;
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) continue;
                if (not graph[nx][ny]) continue;
                
                if (limits[x][y] > 0 or limits[nx][ny] > 0) {
                    int value = 0;
                    if (limits[x][y] == 0) value = limits[nx][ny];
                    else if (limits[nx][ny] == 0) value = limits[x][y];
                    else value = min(limits[x][y], limits[nx][ny]);
                    
                    vector<int> edge = { value, x * MAX + y, nx * MAX + ny };
                    edges.push_back(edge);
                } else {
                    merge(x * MAX + y, nx * MAX + ny);   
                }
            }
        }
    }
    
    sort(edges.rbegin(), edges.rend());
    
    for (int i = 1; i < n; i++) {
        bool flag = find(cities[0]) == find(cities[i]);
        check[i] = flag;
    }
    
    for (const vector<int> &edge : edges) {
        int w = edge[0];
        int x = edge[1], y = edge[2];
        
        bool flag = merge(x, y);
        if (!flag) continue;
        
        for (int i = 1; i < n; i++) {
            if (check[i]) continue;
            else if (find(cities[0]) != find(cities[i])) continue;
            
            check[i] = true;
            result[i - 1] = w;
        }
    }
    
    return result;
}

vector<int> solution(vector<vector<int>> cities, vector<vector<int>> roads) {
    init(cities, roads);
    vector<int> answer = mst(cities);
    return answer;
}
