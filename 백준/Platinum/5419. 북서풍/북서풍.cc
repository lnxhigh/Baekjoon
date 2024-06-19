#include <bits/stdc++.h>
#define ll long long
using namespace std;
using Point = pair<int,int>;

int TC, N;
const int N_MAX = 75001;
Point Island[N_MAX];
ll SegTree[N_MAX << 2];
int Count[N_MAX];

void initialize() {
    for (int i = 0; i < N_MAX; i++) {
        Island[i] = { 0, 0 };
    }
    memset(SegTree, 0, sizeof(SegTree));
    memset(Count, 0, sizeof(Count));
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        Island[i] = { X, Y };
    }
}

void compress(Point Island[N_MAX], int N) {
    vector<int> X(N, 0), Y(N, 0);
    for (int i = 0; i < N; i++) {
        X[i] = Island[i].first;
        Y[i] = Island[i].second;
    }
    
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    
    X.erase(unique(X.begin(), X.end()), X.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());

    int XL = X.size(), YL = Y.size();
    unordered_map<int,int> RankX, RankY;
    for (int i = 0; i < XL; i++) { RankX[X[i]] = i; }
    for (int i = 0; i < YL; i++) { RankY[Y[i]] = i; }

    for (int i = 0; i < N; i++) {
        int a = RankX[Island[i].first];
        int b = RankY[Island[i].second];
        Island[i] = { a, b };
    }
}

ll query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return SegTree[node];
    
    int mid = (start + end) / 2;
    ll leftQuery = query(node*2, start, mid, left, right);
    ll rightQuery = query(node*2+1, mid+1, end, left, right);
    return leftQuery + rightQuery;
}

void update(int node, int start, int end, int index, int value) {
    if (index < start || index > end) return;
    if (start == end) {
        SegTree[node] = 1LL * value;
        return;
    }

    int mid = (start + end) / 2;
    update(node*2, start, mid, index, value);
    update(node*2+1, mid+1, end, index, value);

    SegTree[node] = SegTree[node*2] + SegTree[node*2+1];
}

ll solve(Point Island[N_MAX]) {
    ll res = 0;
    for (int i = 0; i < N; i++) {
        int V = Island[i].second;
        res += query(1, 0, N-1, V, N-1);

        Count[V]++;
        update(1, 0, N-1, V, Count[V]);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> TC;
    while (TC--) {
        initialize();
        input();
        compress(Island, N);
        sort(Island, Island + N, [] (Point &left, Point &right) {
            if (left.first != right.first) return left.first < right.first;
            return left.second > right.second;
        });

        ll res = solve(Island);
        cout << res << '\n';
    }

    return 0;
}
