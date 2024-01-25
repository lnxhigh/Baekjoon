#include <iostream>
using namespace std;

int N, M;
char map_[1001][1001];
int parent[1000*1000+1] = {0};
int group[1000*1000+1] = {0};

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (x > y) parent[x] = y;
    else parent[y] = x;
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    for (int i = 0; i < N*M; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < N; i++) {
        char line[1001];
        cin >> line;
        for (int j = 0; j < M; j++) {
            map_[i][j] = line[j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char dir = map_[i][j];
            int i_next = i, j_next = j;       
            if      (dir == 'L') j_next--;
            else if (dir == 'R') j_next++;
            else if (dir == 'U') i_next--;
            else if (dir == 'D') i_next++;
                    
            merge(i*M + j, i_next*M + j_next);
        }
    }

    int component = 0;
    for (int i = 0; i < N*M; i++) {
        group[find(i)]++;
    }
    for (int i = 0; i < N*M; i++) {
        if (group[i] > 0) component++;
    }
    cout << component << '\n';

    return 0;
}