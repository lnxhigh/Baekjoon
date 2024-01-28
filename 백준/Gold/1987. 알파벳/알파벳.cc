#include <iostream>
#include <set>
using namespace std;

int R, C;
char board[20][20];
int answer = 0;
int dr[4] = { -1, +1, 0, 0 };
int dc[4] = { 0, 0, -1, +1 };
bool visited[20][20] = {false,};
int alphabets[26] = {0,};

void backtrack(int r, int c, int depth) {
    if (depth > answer) answer = depth;

    for (int i = 0; i < 4; i++) {
        // Check if valid
        int r_next = r + dr[i];
        int c_next = c + dc[i];
        if (r_next < 0 || r_next >= R) continue;
        if (c_next < 0 || c_next >= C) continue;

        if (visited[r_next][c_next]) continue;

        char alphabet_next = board[r_next][c_next];
        if (alphabets[alphabet_next - 'A']) continue;

        // Backtracking
        alphabets[alphabet_next - 'A'] = 1;
        visited[r_next][c_next] = true;
        backtrack(r_next, c_next, depth+1);
        alphabets[alphabet_next - 'A'] = 0;
        visited[r_next][c_next] = false;
    }    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    // Input
    cin >> R >> C;
    for (int r = 0; r < R; r++) {
        char line[21];
        cin >> line;
        for (int c = 0; c < C; c++) {
            board[r][c] = line[c];
        }
    }

    // Init
    visited[0][0] = true;
    alphabets[board[0][0] - 'A'] = 1;

    // Search
    backtrack(0, 0, 0);

    cout << ++answer << '\n';
   
    return 0;
}