#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
int N, K;
int A[100][100];
int D[100][100];

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };

int diff() {
    int min_val = 1 << 30;
    int max_val = 0;
    for (int i = 0; i < N; i++) {
        min_val = min(min_val, A[0][i]);
        max_val = max(max_val, A[0][i]);
    }

    return max_val - min_val;
}

void add() {
    int val = 1 << 30;
    for (int i = 0; i < N; i++) {
        val = min(val, A[0][i]);
    }
    for (int i = 0; i < N; i++) {
        if (A[0][i] == val) A[0][i]++;
    }
}

pair<int,int> rotate(pair<int,int> from, pair<int,int> pivot) {
    auto [x, y] = from;
    auto [px, py] = pivot;

    int nx = px + (py - y);
    int ny = py - (px - x);
    return { nx, ny };
}

int measure() {
    int ret = 0;
    for (int col = 0; col < N; col++) {
        int cnt = 0;
        for (int row = 0; row < N; row++) {
            if (A[row][col]) cnt++;
            else break;
        }
        ret = max(ret, cnt);
    }

    return ret;
}

bool arrange(int maxH) {
    if (maxH == 1) {
        swap(A[0][0], A[1][1]);
        return true;
    }

    int leftmost = -1;
    int rightmost = -1;

    for (int col = 0; col < N; col++) {
        if (A[1][col] == 0) continue;
        
        if (leftmost == -1) {
            leftmost = col;
        }
        rightmost = col;
    }

    if (rightmost + maxH >= N) {
        return false;
    }

    pair<int,int> pivot = { 0, rightmost + 1 };
    for (int col = leftmost; col <= rightmost; col++) {
        for (int row = 0; row < maxH; row++) {
            if (A[row][col] == 0) continue;
            pair<int,int> from = { row, col };
            auto [nx, ny] = rotate(from, pivot);
            swap(A[row][col], A[nx][ny]);
        }
    }

    return true;
}

void move(int maxH) {
    memset(D, 0, sizeof(D));
    for (int row = 0; row < maxH; row++) {
        for (int col = 0; col < N; col++) {
            if (A[row][col] == 0) continue;
            
            for (int i = 0; i < 4; i++) {
                int nx = row + dx[i];
                int ny = col + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (A[nx][ny] == 0 || A[row][col] <= A[nx][ny]) continue;
                
                int d = (A[row][col] - A[nx][ny]) / 5;
                D[row][col] -= d;
                D[nx][ny] += d;
            }
        }
    }

    for (int row = 0; row < maxH; row++) {
        for (int col = 0; col < N; col++) {
            A[row][col] += D[row][col];
        }
    }
}

void flatten(int maxH) {
    vector<int> V;
    V.reserve(N);

    for (int col = 0; col < N; col++) {
        for (int row = 0; row < maxH; row++) {
            if (A[row][col] == 0) continue;
            V.push_back(A[row][col]);
        }
    }

    memset(A, 0, sizeof(A));
    for (int i = 0; i < N; i++) {
        A[0][i] = V[i];
    }
}

void flip() {
    int half = N / 2, quarter = N / 4;
    for (int i = 0; i < half; i++) {
        swap(A[0][i], A[1][N - 1 - i]);
    }
    
    pair<int,int> first =  { 1, half + quarter - 1 };
    pair<int,int> second = { 1, half + quarter };
    
    for (int col = half; col < half + quarter; col++) {
        for (int row = 0; row < 2; row++) {
            pair<int,int> cur = { row, col };
            cur = rotate(cur, first);
            cur = rotate(cur, second);

            auto [nx, ny] = cur;
            swap(A[row][col], A[nx][ny]);
        }
    }
}

void organize() {
    // Fig. 2
    add();

    // Fig. 3 - 6
    int maxH = 1;
    while (true) {
        bool canRotate = arrange(maxH);
        if (!canRotate) break;
        maxH = measure();
    }

    // Fig. 7 - 8
    move(maxH);
    flatten(maxH);

    // Fig. 9 - 12
    flip();
    move(4);
    flatten(4);
}

int solve() {
    int delta = diff();
    if (delta <= K) return 0;
    
    int cnt = 0;
    while (true) {
        organize();
        cnt++;
        
        int delta = diff();
        if (delta <= K) break;
    }
    
    return cnt;
}

int main() {
    FastIO
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> A[0][i];

    int ans = solve();
    cout << ans << '\n';
    return 0;
}
