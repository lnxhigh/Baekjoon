#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const long long INF = 1LL << 60;

int N, R;
map<string,int> city;

int M;
int travel[200];

int K;
map<string,int> transport;
vector<string> T = { 
    "Subway", "Bus", "Taxi’", "Airplane", "KTX",
    "S-Train", "V-Train", 
    "ITX-Saemaeul", "ITX-Cheongchun", "Mugunghwa" 
};

long long D[100][100], P[100][100];

void input() {
    // 1 - 2
    cin >> N >> R; 
    R *= 2;

    for (int i = 0; i < N; i++) {
        string name; cin >> name;
        city[name] = i;
    }
    
    // 3 - 4
    cin >> M;
    for (int i = 0; i < M; i++) {
        string name; cin >> name;
        travel[i] = city[name];
    }

    // 5
    cin >> K;
    
    for (int i = 0; i < (int) T.size(); i++) {
        transport[T[i]] = i;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) D[i][j] = P[i][j] = 0;
            else D[i][j] = P[i][j] = INF;
        }
    }

    // 6
    for (int i = 0; i < K; i++) {
        string Type, S, E;
        long long Cost;
        cin >> Type >> S >> E >> Cost;
        Cost *= 2;
        
        int x = city[S], y = city[E], t = transport[Type];
        
        D[x][y] = min(D[x][y], Cost);
        D[y][x] = min(D[y][x], Cost);

        if (t > 6) Cost = 0;
        else if (t > 4) Cost /= 2;
        P[x][y] = min(P[x][y], Cost);
        P[y][x] = min(P[y][x], Cost);
    }
}

void solve() {
    // Floyd
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                P[i][j] = min(P[i][j], P[i][k] + P[k][j]);
            }
        }
    }

    // Result
    long long without = 0, with = R;
    for (int i = 0; i < M - 1; i++) {
        int src = travel[i], dst = travel[i + 1];
        without += D[src][dst];
        with    += P[src][dst];
    }
    
    string ans = (with < without) ? "Yes" : "No";
    cout << ans << '\n';
}

int main() {
    FastIO
    input();
    solve();
    return 0;
}
