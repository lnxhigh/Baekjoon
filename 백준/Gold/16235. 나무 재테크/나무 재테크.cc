#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int x, y;
    int age;
};

int N, M, K;
const int MAX = 1 << 4;
int A[MAX][MAX], B[MAX][MAX];
vector<Tree> Forest[MAX][MAX];

int dx[8] = { -1, 0, +1, 0, -1, +1, +1, -1 };
int dy[8] = { 0, -1, 0, +1, -1, -1, +1, +1 }; 

void update() {
    // Spring and Summer
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            vector<Tree> newTrees;
            vector<Tree> &trees = Forest[x][y];
            int &nourishment = B[x][y];
            int supplement = 0;
            
            // Eat from younger tree
            sort(trees.begin(), trees.end(), [] (const Tree &left, const Tree &right) {
                return left.age < right.age;
            });

            for (const Tree &tree : trees) {
                if (nourishment >= tree.age) {
                    // Take in nourishment
                    nourishment -= tree.age;
                    Tree newTree = { x, y, tree.age+1 }; 
                    newTrees.push_back(newTree);
                }
                else {
                    // Die
                    supplement += tree.age / 2;
                }
            }

            Forest[x][y] = newTrees;
            B[x][y] += supplement;
        }
    }

    // Fall
    vector<Tree> newTrees;

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            for (const Tree &tree : Forest[x][y]) {
                if (tree.age % 5 != 0) continue;

                // Reproduce if the age is a multiple of five
                for (int dir = 0; dir < 8; dir++) {
                    int nx = x + dx[dir], ny = y + dy[dir];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    Tree newTree = { nx, ny, 1 };
                    newTrees.push_back(newTree);
                }
            }
        }
    }

    for (const Tree &newTree : newTrees) {
        Forest[newTree.x][newTree.y].push_back(newTree);
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
        Tree tree = { --x, --y, z };
        Forest[tree.x][tree.y].push_back(tree);
    }

    for (int year = 0; year < K; year++) {
        update();
    }

    int res = countTrees();
    cout << res << '\n';

    return 0;
}
