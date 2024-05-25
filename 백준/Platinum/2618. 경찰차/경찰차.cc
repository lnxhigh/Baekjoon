#include <bits/stdc++.h>
#define N_MAX 1001
#define W_MAX 1001
#define INF 100000000
using namespace std;

int N, W;
pair<int,int> loc[2][W_MAX];
int dp[W_MAX][W_MAX]; // dp[x][y] - 경찰차 A, B 가 마지막으로 처리한 사건이 x, y
tuple<int,int,int> track[W_MAX][W_MAX];

enum { A, B };

int dist(pair<int,int> &from, pair<int,int> &to) {
    int dx = from.first - to.first;
    int dy = from.second - to.second;
    return abs(dx) + abs(dy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> W;

    pair<int,int> startA = { 1, 1 };
    pair<int,int> startB = { N, N };
    fill(&dp[0][0], &dp[W][W]+1, INF);

    loc[A][0] = { 1, 1 };
    loc[B][0] = { N, N };
    for (int i = 1; i <= W; i++) {
        int x, y;
        cin >> x >> y;
        loc[A][i] = loc[B][i] = { x, y };
    }

    dp[1][0] = dist(loc[A][0], loc[A][1]);
    dp[0][1] = dist(loc[B][0], loc[B][1]);
    track[1][0] = make_tuple(0, 0, A);
    track[0][1] = make_tuple(0, 0, B);

    for (int i = 1; i < W; i++) {
        for (int j = 0; j < i; j++) {
            
            dp[i+1][j] = dp[i][j] + dist(loc[A][i], loc[A][i+1]);
            dp[j][i+1] = dp[j][i] + dist(loc[B][i], loc[B][i+1]);
            
            track[i+1][j] = make_tuple(i, j, A);
            track[j][i+1] = make_tuple(j, i, B);

            if (dp[i][i+1] > dp[i][j] + dist(loc[B][j], loc[B][i+1])) {
                dp[i][i+1] = dp[i][j] + dist(loc[B][j], loc[B][i+1]);
                track[i][i+1] = make_tuple(i, j, B);
            }
            if (dp[i+1][i] > dp[j][i] + dist(loc[A][j], loc[A][i+1])) {
                dp[i+1][i] = dp[j][i] + dist(loc[A][j], loc[A][i+1]);
                track[i+1][i] = make_tuple(j, i, A);
            }
        }
    }

    int answer = INF;
    int x, y, car;
    for (int i = 0; i < W; i++) {
        if (answer > dp[W][i]) {
            answer = dp[W][i];
            x = W; y = i;
        }
        if (answer > dp[i][W]) {
            answer = dp[i][W];
            x = i; y = W;
        }
    }
    
    cout << answer << '\n';
    
    vector<int> cars;
    tuple<int,int,int> t = track[x][y];
    for (int i = 0; i < W; i++) {
        x = get<0>(t); y = get<1>(t);
        car = get<2>(t) + 1;
        cars.push_back(car);
        t = track[x][y];
    }

    for (int i = W-1; i >= 0; i--) {
        cout << cars[i] << '\n';
    }
    
    return 0;
}
