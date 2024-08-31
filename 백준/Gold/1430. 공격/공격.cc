#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using Point = pair<int,int>;

int N, R, D, EX, EY;
const int MAX = 1 << 6;
Point P[MAX];

vector<int> graph[MAX];
bool visited[MAX];
int depth[MAX];

int main() {
    cin >> N >> R >> D >> EX >> EY;
    P[0] = { EX, EY };
    for (int i = 1; i <= N; i++) {
        int x, y; cin >> x >> y;
        P[i] = { x, y };
    }

    for (int i = 0; i <= N; i++) {
        for (int j = i+1; j <= N; j++) {
            int dx = P[i].X - P[j].X;
            int dy = P[i].Y - P[j].Y;

            if (dx*dx + dy*dy > R*R) continue;

            graph[i].push_back(j);
            graph[j].push_back(i);
        }
    }
    
    queue<int> q;
    q.push(0);
    visited[0] = true;

    memset(depth, -1, sizeof(depth));
    depth[0] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (visited[next]) continue;

            visited[next] = true;
            depth[next] = depth[cur] + 1;
            q.push(next);
        }
    }

    double damage = 0;
    for (int i = 1; i <= N; i++) {
        if (depth[i] == -1) continue;
        
        double attenuation = 1;
        for (int k = 0; k < depth[i]-1; k++) attenuation *= 0.5;
        damage += attenuation * D;
    }

    cout << setprecision(16);
    cout << damage << '\n';
    return 0;
}
