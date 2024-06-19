#include <bits/stdc++.h>
#define ll long long
using namespace std;
using Point = pair<int,int>;

int TC, N;
const int N_MAX = 75001;
Point Island[N_MAX];
ll SegTree[N_MAX << 2];
int Count[N_MAX];

// 먼저 좌표 압축을 진행해서 좌표들을 0 ~ 75000 사이의 값으로 변환한다
// 좌표들은 어차피 대소 관계가 중요하므로 압축해도 답을 변화시키지 않으며
// 압축된 좌표들은 인덱스로 활용되면서 빠른 처리를 돕는다

// 그 다음으로 좌표 배열을 정렬하고
// 왼쪽에서 오른쪽으로 그리고 위에서 아래로 순회한다

// Count 배열은 좌표가 Y 이상인 수들의 개수를 저장한다
// 순회하면서 좌표가 Y 이상인 수들의 개수를 구한다
// 이때 세그먼트 트리를 이용해서 구간합을 빠르게 구하면
// 좌표가 Y 이상인 수들의 개수를 빠르게 구할 수 있다

// 해당 점의 처리가 끝났으면 Count 를 하나 증가시키고
// 세그먼트 트리를 업데이트한다

// 위와 같은 풀이의 아이디어를 구현했는데
// 좀 복잡해서 확실히 맞을지는 잘 모르겠다

// 오버플로우 가능성?
// 아니면 논리 오류인지 잘 모르겠다

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

ll query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return SegTree[node];
    
    int mid = (start + end) / 2;
    ll leftQuery = query(node*2, start, mid, left, right);
    ll rightQuery = query(node*2+1, mid+1, end, left, right);
    return leftQuery + rightQuery;
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

        ll res = 0;
        for (int i = 0; i < N; i++) {
            int V = Island[i].second;
            res += query(1, 0, N-1, V, N-1);

            Count[V]++;
            update(1, 0, N-1, V, Count[V]);
        }

        cout << res << '\n';
    }

    return 0;
}
