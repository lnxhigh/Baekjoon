#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

struct Block {
    int x;
    int y;
    int value;
};

int N;
int board[20][20];
int answer = 1;
vector<int> X(20, 0);
vector<int> Y(20, 0);
vector<Block> block;
enum { UP, DOWN, LEFT, RIGHT };

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int value;
            cin >> value;
            board[i][j] = value;
            if (value != 0) {
                block.push_back({i,j,value});
                X[i]++; Y[j]++;
            }
        }
    }
}

void up() {
    sort(block.begin(), block.end(), [] (Block A, Block B) {
        if (A.y < B.y) return true;
        else if (A.y > B.y) return false;
        else {
            if (A.x < B.x) return true;
            else return false;
        }
    });

    stack<Block> s;
    queue<Block> temp;
    for (Block x: block) temp.push(x);

    for (int i = 0; i < N; i++) {
        int p = -1;
        Block A = {0, 0, -1};

        bool merged = false;
        int J = Y[i];
        for (int j = 0; j < J; j++) {
            Block B = temp.front();
            temp.pop();
            if (merged) {
                merged = false;
                B.x = ++p;
                s.push(B);
                A = B;
                continue;
            }

            if (A.value == B.value) {
                merged = true;
                s.top().value *= 2;
            }
            else {
                B.x = ++p;
                s.push(B);
                A = B;
            }
        }

    }
    
    for (Block A : block) {
        X[A.x] = 0; Y[A.y] = 0;
    }
    block.clear();
    while (not s.empty()) {
        Block A = s.top();
        s.pop();
        block.push_back(A);
        X[A.x]++; Y[A.y]++;
    }
}


void down() {
    sort(block.begin(), block.end(), [] (Block A, Block B) {
        if (A.y < B.y) return true;
        else if (A.y > B.y) return false;
        else {
            if (A.x > B.x) return true;
            else return false;
        }
    });

    stack<Block> s;
    queue<Block> temp;
    for (Block x: block) temp.push(x);

    for (int i = 0; i < N; i++) {
        int p = N;
        Block A = {0, 0, -1};

        bool merged = false;
        int J = Y[i];
        for (int j = 0; j < J; j++) {
            Block B = temp.front();
            temp.pop();
            if (merged) {
                merged = false;
                B.x = --p;
                s.push(B);
                A = B;
                continue;
            }

            if (A.value == B.value) {
                merged = true;
                s.top().value *= 2;
            }
            else {
                B.x = --p;
                s.push(B);
                A = B;
            }
        }

    }
    
    for (Block A : block) {
        X[A.x] = 0; Y[A.y] = 0;
    }
    block.clear();
    while (not s.empty()) {
        Block A = s.top();
        s.pop();
        block.push_back(A);
        X[A.x]++; Y[A.y]++;
    }
}


void left() {
    sort(block.begin(), block.end(), [] (Block A, Block B) {
        if (A.x < B.x) return true;
        else if (A.x > B.x) return false;
        else {
            if (A.y < B.y) return true;
            else return false;
        }
    });

    stack<Block> s;
    queue<Block> temp;
    for (Block x: block) temp.push(x);

    for (int i = 0; i < N; i++) {
        int p = -1;
        Block A = {0, 0, -1};

        bool merged = false;
        int J = X[i];
        for (int j = 0; j < J; j++) {
            Block B = temp.front();
            temp.pop();
            if (merged) {
                merged = false;
                B.y = ++p;
                s.push(B);
                A = B;
                continue;
            }

            if (A.value == B.value) {
                merged = true;
                s.top().value *= 2;
            }
            else {
                B.y = ++p;
                s.push(B);
                A = B;
            }
        }

    }
    
    for (Block A : block) {
        X[A.x] = 0; Y[A.y] = 0;
    }
    block.clear();
    while (not s.empty()) {
        Block A = s.top();
        s.pop();
        block.push_back(A);
        X[A.x]++; Y[A.y]++;
    }
}


void right() {
    sort(block.begin(), block.end(), [] (Block A, Block B) {
        if (A.x < B.x) return true;
        else if (A.x > B.x) return false;
        else {
            if (A.y > B.y) return true;
            else return false;
        }
    });

    stack<Block> s;
    queue<Block> temp;
    for (Block x: block) temp.push(x);

    for (int i = 0; i < N; i++) {
        int p = N;
        Block A = {0, 0, -1};

        bool merged = false;
        int J = X[i];
        for (int j = 0; j < J; j++) {
            Block B = temp.front();
            temp.pop();
            if (merged) {
                merged = false;
                B.y = --p;
                s.push(B);
                A = B;
                continue;
            }

            if (A.value == B.value) {
                merged = true;
                s.top().value *= 2;
            }
            else {
                B.y = --p;
                s.push(B);
                A = B;
            }
        }

    }
    
    for (Block A : block) {
        X[A.x] = 0; Y[A.y] = 0;
    }
    block.clear();
    while (not s.empty()) {
        Block A = s.top();
        s.pop();
        block.push_back(A);
        X[A.x]++; Y[A.y]++;
    }
}


void control(int x) {
    switch (x) {
        case UP: up(); break;
        case DOWN: down(); break;
        case LEFT: left(); break;
        case RIGHT: right(); break;
    }
}

int Max() {
    int m = 1;
    for (Block A : block) {
        if (A.value > m) m = A.value;
    }
    return m;
}

void investigate(int count) {
    if (count == 5) {
        int k = Max();
        if (answer < k) answer = k;

        return;
    }
    
    for (int i = 0; i < 4; i++) {
        vector<Block> temp = block;
        vector<int> temp_X = X;
        vector<int> temp_Y = Y;

        control(i);
        investigate(count+1);

        block = temp;
        X = temp_X;
        Y = temp_Y;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    input();
    investigate(0);
    cout << answer << '\n';
    
    return 0;
}