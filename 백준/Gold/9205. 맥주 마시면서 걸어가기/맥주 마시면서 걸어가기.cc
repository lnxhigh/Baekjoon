#include <bits/stdc++.h>
using namespace std;
using xy = pair<int,int>;

int TC;
int N;
const int MAX = 1 << 7;
vector<xy> points;
bool graph[MAX][MAX];

void initialize(int N) {
    points.clear();
    for (int i = 0; i <= N+1; i++) {
        for (int j = 0; j <= N+1; j++) {
            graph[i][j] = false;
        }
    }
}

void Input(int N) {
    for (int i = 0; i < N+2; i++) {
        int X, Y;
        cin >> X >> Y;
        points.push_back({ X, Y });
    }
}

void Build(int N) {
    for (int i = 0; i <= N+1; i++) {
        for (int j = 0; j <= N+1; j++) {
            int dx = points[i].first - points[j].first;
            int dy = points[i].second - points[j].second;
            int dist = abs(dx) + abs(dy);

            if (dist <= 1000) graph[i][j] = true;
        }
    }
}

void Floyd(int N, bool arr[MAX][MAX]) {
    int n = N + 2;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][k] && arr[k][j]) arr[i][j] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> TC;
    while (TC--) {
        cin >> N;
        initialize(N);
        Input(N);
        Build(N);
        Floyd(N, graph);
        
        bool canReach = graph[0][N+1];
        string res = canReach ? "happy" : "sad";
        cout << res << '\n';
    }

    return 0;
}
