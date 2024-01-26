#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Shark {
public:
    int i, r, c, s, d, z;
};

bool operator< (const Shark &left, const Shark &right) {
    if (left.s < right.s) return true;
    else if (left.s > right.s) return false;
    else {
        if (left.i < right.i) return true;
        else if (left.i > right.i) return false;
        else return false;
    }
    return false;
}

enum { MIDDLE, UP, DOWN, RIGHT, LEFT };

multiset<Shark> sharks;

int R, C; // Grid size
int M; // The number of sharks

int r, c; // location
int s; // speed
int d; // direction
int z; // size. 1 = up, 2 = down, 3 = right, 4 = left

int answer = 0;

void print_shark(multiset<Shark> &sharks) {
    int grid[101][101] = {0,};
    for (auto iter = sharks.begin(); iter != sharks.end(); ++iter) {
        grid[iter->r][iter->c] = iter->i;
    }
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cout << grid[r][c] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int capture_shark(int t, multiset<Shark> &sharks) {
    vector<Shark> captured_sharks;
    for (auto iter = sharks.begin(); iter != sharks.end(); ++iter) {
        Shark shark = *iter;
        if (shark.c != t) continue;
        captured_sharks.push_back(shark);
    }

    if (captured_sharks.empty()) return 0;
    
    Shark captured_shark = *captured_sharks.begin();
    for (Shark shark : captured_sharks) {
        if (shark.r < captured_shark.r) captured_shark = shark;
    }

    sharks.erase(captured_shark);    
    return captured_shark.z;
};

void move_shark(multiset<Shark> &sharks) {
    multiset<Shark> new_sharks;
    Shark grid[101][101];
    int visited[101][101] = {0,};

    int dr[5] = {0, -1, +1, 0, 0};
    int dc[5] = {0, 0, 0, +1, -1};

    for (auto iter = sharks.begin(); iter != sharks.end(); ++iter) {
        Shark shark = *iter;
        
        shark.r += shark.s * dr[shark.d];
        shark.c += shark.s * dc[shark.d];

        while (shark.r <= 0 || shark.r > R) {
            if (shark.r <= 0) { shark.r = 2 - shark.r; shark.d = DOWN; }
            else if (shark.r > R) { shark.r = 2*R - shark.r; shark.d = UP; }
        }
        while (shark.c <= 0 || shark.c > C) {
            if (shark.c <= 0) { shark.c = 2 - shark.c; shark.d = RIGHT; }
            else if (shark.c > C) { shark.c = 2*C - shark.c; shark.d = LEFT; }
        }
        
        if (visited[shark.r][shark.c]) {
            Shark old_shark = grid[shark.r][shark.c];
        
            if (old_shark.z > shark.z) continue;    
            new_sharks.erase(old_shark);
            grid[shark.r][shark.c] = shark;
            new_sharks.insert(shark);
        }
        else {
            visited[shark.r][shark.c] = 1;
            grid[shark.r][shark.c] = shark;
            new_sharks.insert(shark);
        }
    }

    sharks.clear();
    sharks = new_sharks;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> R >> C >> M;
    for (int i = 1; i <= M; i++) {
        cin >> r >> c >> s >> d >> z;
        if (d == 1 || d == 2) s %= 2*(R-1);
        else s %= 2*(C-1);
        
        Shark shark = { i, r, c, s, d, z };
        sharks.insert(shark);
    }
    
    for (int t = 1; t <= C; t++) {
        answer += capture_shark(t, sharks);
        move_shark(sharks);
    }
    cout << answer ;

    return 0;
}