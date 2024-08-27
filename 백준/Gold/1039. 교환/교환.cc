#include <bits/stdc++.h>
using namespace std;

int N, K;
int L;
const int MAX = 1 << 20;
bool V[MAX];
int ten[MAX];

void init() {
    int mul = 1;
    for (int i = 0; i < 9; i++) {
        ten[i] = mul;
        mul *= 10;
    }

    L = to_string(N).size();
}

int swap(int X, int i, int j) {
    int a = (X / ten[i]) % 10;
    int b = (X / ten[j]) % 10;

    if (a == 0 && j == L-1) return -1;
    int Y = X - a * ten[i] - b * ten[j];
    Y += a * ten[j] + b * ten[i];

    return Y;
}

int solve(int N, int K) {
    int res = -1;

    vector<pair<int,int>> all;
    queue<pair<int,int>> q;
    q.push({ N, 0 });

    while (!q.empty()) {
        auto front = q.front();
        int X = front.first;
        int depth = front.second;
        if (depth > 0) V[X] = true;
        
        q.pop();
        
        if (depth > K) continue;
        all.push_back(front);
        
        for (int i = 0; i < L; i++) {
            for (int j = i+1; j < L; j++) {
                int Y = swap(X, i, j);
                if (Y == -1 || V[Y]) continue;
                q.push({ Y, depth+1 });
            }
        }
    }

    for (const auto &p : all) {
        int X = p.first, depth = p.second;
        int diff = K - depth;
        if (diff % 2 == 0) {
            if (depth > 0) res = max(res, X);
            continue;
        }

        for (int i = 0; i < L; i++) {
            for (int j = i+1; j < L; j++) {
                int Y = swap(X, i, j);
                if (Y != -1) res = max(res, Y);
            }
        }
    }

    return res;
}

int main() {
    cin >> N >> K;
    init();
    cout << solve(N, K) << '\n';
    return 0;
}
