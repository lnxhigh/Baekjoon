#include <bits/stdc++.h>
using namespace std;

// No sort version 

int N, M, K;
const int MAX = 1 << 4;
int A[MAX][MAX], B[MAX][MAX];
vector<int> InitForest[MAX][MAX];
deque<int> Forest[MAX][MAX];

int dx[8] = { -1, 0, +1, 0, -1, +1, +1, -1 };
int dy[8] = { 0, -1, 0, +1, -1, -1, +1, +1 }; 

void start() {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            vector<int> &trees = InitForest[x][y];
            sort(trees.begin(), trees.end());
            
            deque<int> dq;
            for (const int &age : trees) {
                dq.push_back(age);
            }
            Forest[x][y] = dq;
        }
    }
}

void update() {
    // Spring and Summer
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            deque<int> newTrees;
            deque<int> &trees = Forest[x][y];
            int &nourishment = B[x][y];
            int supplement = 0;

            for (const int &age : trees) {
                if (nourishment >= age) {
                    // Take in nourishment
                    nourishment -= age;
                    newTrees.push_back(age + 1);
                }
                else {
                    // Die
                    supplement += age / 2;
                }
            }

            Forest[x][y] = newTrees;
            B[x][y] += supplement;
        }
    }

    // Fall
    vector<pair<int,int>> locs;

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            for (const int &age : Forest[x][y]) {
                if (age % 5 != 0) continue;

                // Reproduce if the age is a multiple of five
                for (int dir = 0; dir < 8; dir++) {
                    int nx = x + dx[dir], ny = y + dy[dir];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    locs.push_back({ nx, ny });
                }
            }
        }
    }

    for (const pair<int,int> &loc : locs) {
        int x = loc.first, y = loc.second;
        int age = 1;
        Forest[x][y].push_front(age);
    }

    // Winter
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            B[x][y] += A[x][y];
        }
    }
}

int countTrees() {
    int res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res += (int) Forest[i][j].size();
        }
    }
    return res;
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            B[i][j] = 5;
        }
    }

    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        InitForest[--x][--y].push_back(z);
    }

    start();
    for (int year = 0; year < K; year++) {
        update();
    }

    int res = countTrees();
    cout << res << '\n';

    return 0;
}
