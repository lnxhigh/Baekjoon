#include <bits/stdc++.h>
#define X first 
#define Y second
#define ll long long
using namespace std;

int N;
const int N_MAX = 10;
int A, B;
ll  P, Q;

struct Edge {
    int next;
    pair<ll,ll> ratio;
};

vector<Edge> graph[N_MAX];
bool visited[N_MAX];
pair<ll,ll> R[N_MAX];

void dfs(int cur, pair<ll,ll> ratio) {
    visited[cur] = true;
    R[cur] = ratio;
    for (Edge e : graph[cur]) {
        int next = e.next;
        if (visited[next]) continue;

        pair<ll,ll> newRatio = { ratio.X * e.ratio.X, ratio.Y * e.ratio.Y };
        dfs(next, newRatio);
    }
    return;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

int main() {
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        cin >> A >> B >> P >> Q;
        graph[A].push_back({ B, { P, Q } });
        graph[B].push_back({ A, { Q, P } });
    }

    int start = 0;
    pair<ll,ll> defaultRatio = { 1, 1 };
    dfs(start, defaultRatio);

    for (int i = 0; i < N; i++) {
        ll k = gcd(R[i].X, R[i].Y);
        R[i].X /= k; R[i].Y /= k;
    }

    ll k = 1;
    for (int i = 0; i < N; i++) {
        k = lcm(k, R[i].X);
    }
   
    for (int i = 0; i < N; i++) {
        ll value = k / R[i].X * R[i].Y;
        cout << value << ' ';
    }
    cout << '\n';

    return 0;
}
