#include <iostream>
#include <queue>
#include <utility>
using namespace std;
using xy = pair<int,int>;

int N, M;
char board[11][11];
xy red, blue, destination;
typedef struct marble {
    xy red;
    xy blue;
} Marble;
queue<pair<Marble, int>> q;

Marble marble;

void input(char board[11][11]) {
    cin >> N >> M;

    for (int r = 0; r < N; r++) {
        char line[11];
        cin >> line;
        for (int c = 0; c < M; c++) {
            board[r][c] = line[c];
            char x = board[r][c];
            if (x == 'R') { red = {r,c}; } 
            else if (x == 'B') { blue = {r,c}; }
            else if (x == 'O') { destination = {r,c}; }
        }
    }

    board[red.first][red.second] = '.';
    board[blue.first][blue.second] = '.';

    marble.red = red;
    marble.blue = blue;
}

void print(Marble marble, char board[11][11]) {
    xy red = marble.red;
    xy blue = marble.blue;
    board[red.first][red.second] = 'R';
    board[blue.first][blue.second] = 'B';
    board[destination.first][destination.second] = 'O';

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    board[red.first][red.second] = '.';
    board[blue.first][blue.second] = '.';
}


Marble up_(Marble marble, char board[11][11]) {
    xy red = marble.red;
    xy blue = marble.blue;

    if (red.second == blue.second) {
        if (red.first < blue.first) {
            // move red first
            board[blue.first][blue.second] = 'B';
            board[destination.first][destination.second] = 'O';
            red.first--;
            while (true) {
                char x = board[red.first][red.second];
                if (x == '.') { red.first--; }
                else if (x == 'O') { break; }
                else if (x == '#') { red.first++; break; }
                else if (x == 'B') { red.first++; break; }
                else { cout << "Error"; }
            }
            board[blue.first][blue.second] = '.';

            // then blue next
            board[red.first][red.second] = 'R';
            board[destination.first][destination.second] = 'O';
            blue.first--;
            while (true) {
                char x = board[blue.first][blue.second];
                if (x == '.') { blue.first--; }
                else if (x == 'O') { break; }
                else if (x == '#') { blue.first++; break; }
                else if (x == 'R') { blue.first++; break; }
                else { cout << "Error"; }
            }
            board[red.first][red.second] = '.';
        }
        
        else if (red.first > blue.first) {
            // move blue first
            board[red.first][red.second] = 'R';
            board[destination.first][destination.second] = 'O';
            blue.first--;
            while (true) {
                char x = board[blue.first][blue.second];
                if (x == '.') { blue.first--; }
                else if (x == 'O') { break; }
                else if (x == '#') { blue.first++; break; }
                else if (x == 'R') { blue.first++; break; }
                else { cout << "Error"; }
            }
            board[red.first][red.second] = '.';
            
            // then red next
            board[blue.first][blue.second] = 'B';
            board[destination.first][destination.second] = 'O';
            red.first--;
            while (true) {
                char x = board[red.first][red.second];
                if (x == '.') { red.first--; }
                else if (x == '#') { red.first++; break; }
                else if (x == 'B') { red.first++; break; }
                else if (x == 'O') { break; }
                else { cout << "Error"; }
            }
            board[blue.first][blue.second] = '.';
        }
    }
    else if (red.second != blue.second) {
        // move red and blue seperately
        
        // move red
        red.first--;
        while (true) {
            char x = board[red.first][red.second];
            if (x == '.') { red.first--; }
            else if (x == 'O') { break; }
            else if (x == '#') { red.first++; break; }
            else { cout << "Error"; }
        }
        
        // move blue
        blue.first--;
        while (true) {
            char x = board[blue.first][blue.second];
            if (x == '.') { blue.first--; }
            else if (x == 'O') { break; }
            else if (x == '#') { blue.first++; break; }
            else { cout << "Error"; }
        }
    }

    return { red, blue };
}


Marble down_(Marble marble, char board[11][11]) {
    xy red = marble.red;
    xy blue = marble.blue;

    if (red.second == blue.second) {
        if (red.first > blue.first) {
            // move red first
            board[blue.first][blue.second] = 'B';
            board[destination.first][destination.second] = 'O';
            red.first++;
            while (true) {
                char x = board[red.first][red.second];
                if (x == '.') { red.first++; }
                else if (x == 'O') { break; }
                else if (x == '#') { red.first--; break; }
                else if (x == 'B') { red.first--; break; }
                else { cout << "Error"; }
            }
            board[blue.first][blue.second] = '.';

            // then blue next
            board[red.first][red.second] = 'R';
            board[destination.first][destination.second] = 'O';
            blue.first++;
            while (true) {
                char x = board[blue.first][blue.second];
                if (x == '.') { blue.first++; }
                else if (x == 'O') { break; }
                else if (x == '#') { blue.first--; break; }
                else if (x == 'R') { blue.first--; break; }
                else { cout << "Error"; }
            }
            board[red.first][red.second] = '.';
        }
        
        else if (red.first < blue.first) {
            // move blue first
            board[red.first][red.second] = 'R';
            board[destination.first][destination.second] = 'O';
            blue.first++;
            while (true) {
                char x = board[blue.first][blue.second];
                if (x == '.') { blue.first++; }
                else if (x == 'O') { break; }
                else if (x == '#') { blue.first--; break; }
                else if (x == 'R') { blue.first--; break; }
                else { cout << "Error"; }
            }
            board[red.first][red.second] = '.';
            
            // then red next
            board[blue.first][blue.second] = 'B';
            board[destination.first][destination.second] = 'O';
            red.first++;
            while (true) {
                char x = board[red.first][red.second];
                if (x == '.') { red.first++; }
                else if (x == '#') { red.first--; break; }
                else if (x == 'B') { red.first--; break; }
                else if (x == 'O') { break; }
                else { cout << "Error"; }
            }
            board[blue.first][blue.second] = '.';
        }
    }
    else if (red.second != blue.second) {
        // move red and blue seperately
        
        // move red
        red.first++;
        while (true) {
            char x = board[red.first][red.second];
            if (x == '.') { red.first++; }
            else if (x == 'O') { break; }
            else if (x == '#') { red.first--; break; }
            else { cout << "Error"; }
        }
        
        // move blue
        blue.first++;
        while (true) {
            char x = board[blue.first][blue.second];
            if (x == '.') { blue.first++; }
            else if (x == 'O') { break; }
            else if (x == '#') { blue.first--; break; }
            else { cout << "Error"; }
        }
    }

    return { red, blue };
}


Marble left_(Marble marble, char board[11][11]) {
    xy red = marble.red;
    xy blue = marble.blue;

    if (red.first == blue.first) {
        if (red.second < blue.second) {
            // move red first
            board[blue.first][blue.second] = 'B';
            board[destination.first][destination.second] = 'O';
            red.second--;
            while (true) {
                char x = board[red.first][red.second];
                if (x == '.') { red.second--; }
                else if (x == 'O') { break; }
                else if (x == '#') { red.second++; break; }
                else if (x == 'B') { red.second++; break; }
                else { cout << "Error"; }
            }
            board[blue.first][blue.second] = '.';

            // then blue next
            board[red.first][red.second] = 'R';
            board[destination.first][destination.second] = 'O';
            blue.second--;
            while (true) {
                char x = board[blue.first][blue.second];
                if (x == '.') { blue.second--; }
                else if (x == 'O') { break; }
                else if (x == '#') { blue.second++; break; }
                else if (x == 'R') { blue.second++; break; }
                else { cout << "Error"; }
            }
            board[red.first][red.second] = '.';
        }
        
        else if (red.second > blue.second) {
            // move blue first
            board[red.first][red.second] = 'R';
            board[destination.first][destination.second] = 'O';
            blue.second--;
            while (true) {
                char x = board[blue.first][blue.second];
                if (x == '.') { blue.second--; }
                else if (x == 'O') { break; }
                else if (x == '#') { blue.second++; break; }
                else if (x == 'R') { blue.second++; break; }
                else { cout << "Error"; }
            }
            board[red.first][red.second] = '.';
            
            // then red next
            board[blue.first][blue.second] = 'B';
            board[destination.first][destination.second] = 'O';
            red.second--;
            while (true) {
                char x = board[red.first][red.second];
                if (x == '.') { red.second--; }
                else if (x == '#') { red.second++; break; }
                else if (x == 'B') { red.second++; break; }
                else if (x == 'O') { break; }
                else { cout << "Error"; }
            }
            board[blue.first][blue.second] = '.';
        }
    }
    else if (red.first != blue.first) {
        // move red and blue seperately
        
        // move red
        red.second--;
        while (true) {
            char x = board[red.first][red.second];
            if (x == '.') { red.second--; }
            else if (x == 'O') { break; }
            else if (x == '#') { red.second++; break; }
            else { cout << "Error"; }
        }
        
        // move blue
        blue.second--;
        while (true) {
            char x = board[blue.first][blue.second];
            if (x == '.') { blue.second--; }
            else if (x == 'O') { break; }
            else if (x == '#') { blue.second++; break; }
            else { cout << "Error"; }
        }
    }

    return { red, blue };
}


Marble right_(Marble marble, char board[11][11]) {
    xy red = marble.red;
    xy blue = marble.blue;

    if (red.first == blue.first) {
        if (red.second > blue.second) {
            // move red first
            board[blue.first][blue.second] = 'B';
            board[destination.first][destination.second] = 'O';
            red.second++;
            while (true) {
                char x = board[red.first][red.second];
                if (x == '.') { red.second++; }
                else if (x == 'O') { break; }
                else if (x == '#') { red.second--; break; }
                else if (x == 'B') { red.second--; break; }
                else { cout << "Error"; }
            }
            board[blue.first][blue.second] = '.';

            // then blue next
            board[red.first][red.second] = 'R';
            board[destination.first][destination.second] = 'O';
            blue.second++;
            while (true) {
                char x = board[blue.first][blue.second];
                if (x == '.') { blue.second++; }
                else if (x == 'O') { break; }
                else if (x == '#') { blue.second--; break; }
                else if (x == 'R') { blue.second--; break; }
                else { cout << "Error"; }
            }
            board[red.first][red.second] = '.';
        }
        
        else if (red.second < blue.second) {
            // move blue first
            board[red.first][red.second] = 'R';
            board[destination.first][destination.second] = 'O';
            blue.second++;
            while (true) {
                char x = board[blue.first][blue.second];
                if (x == '.') { blue.second++; }
                else if (x == 'O') { break; }
                else if (x == '#') { blue.second--; break; }
                else if (x == 'R') { blue.second--; break; }
                else { cout << "Error"; }
            }
            board[red.first][red.second] = '.';
            
            // then red next
            board[blue.first][blue.second] = 'B';
            board[destination.first][destination.second] = 'O';
            red.second++;
            while (true) {
                char x = board[red.first][red.second];
                if (x == '.') { red.second++; }
                else if (x == '#') { red.second--; break; }
                else if (x == 'B') { red.second--; break; }
                else if (x == 'O') { break; }
                else { cout << "Error"; }
            }
            board[blue.first][blue.second] = '.';
        }
    }
    else if (red.first != blue.first) {
        // move red and blue seperately
        
        // move red
        red.second++;
        while (true) {
            char x = board[red.first][red.second];
            if (x == '.') { red.second++; }
            else if (x == 'O') { break; }
            else if (x == '#') { red.second--; break; }
            else { cout << "Error"; }
        }
        
        // move blue
        blue.second++;
        while (true) {
            char x = board[blue.first][blue.second];
            if (x == '.') { blue.second++; }
            else if (x == 'O') { break; }
            else if (x == '#') { blue.second--; break; }
            else { cout << "Error"; }
        }
    }

    return { red, blue };
}


Marble moveTo(Marble marble, int i, char board[11][11]) {
    if      (i == 1) return up_(marble, board);
    else if (i == 2) return down_(marble, board);
    else if (i == 3) return left_(marble, board);
    else if (i == 4) return right_(marble, board);
    else {
        cout << "Error Move" << '\n';
        return marble;
    }
}

int bfs() {
    q.push({marble, 1});
    while (not q.empty()) {
        Marble cur = q.front().first;
        int depth = q.front().second;
        q.pop();
        if (depth > 10) return -1;

        for (int i = 1; i <= 4; i++) {
            Marble next = moveTo(cur, i, board);
            if (next.red != destination and next.blue != destination) {
                q.push({ next, depth+1 });
            }
            else if (next.red == destination and next.blue != destination) {
                return depth; 
            }
            else if (next.red != destination and next.blue == destination) {
                continue; 
            }
            else {
                continue; 
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    input(board);
    cout << bfs();
    return 0;
}