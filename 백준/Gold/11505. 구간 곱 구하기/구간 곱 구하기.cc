#include <bits/stdc++.h>
#define ll long long
#define N_MAX 1000001
#define DIV 1000000007LL
using namespace std;

int N, U, Q;
ll arr[N_MAX];
ll tree[N_MAX << 2];

ll init(int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];

    int mid = (start + end) / 2;
    ll leftInit = init(node*2, start, mid);
    ll rightInit = init(node*2 + 1, mid+1, end);
    return tree[node] = (leftInit * rightInit) % DIV;
}

ll query(int node, int start, int end, int left, int right) {
    if (right < start || left > end) return 1LL;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    ll leftQuery = query(node*2, start, mid, left, right);
    ll rightQuery = query(node*2 + 1, mid+1, end, left, right);
    return (leftQuery * rightQuery) % DIV;
}

void update(int node, int start, int end, int index, ll value) {
    if (index < start || end < index) return;
    if (start == end) {
        tree[node] = value;
        return;
    }

    int mid = (start + end) / 2;
    update(node*2, start, mid, index, value);
    update(node*2 + 1, mid+1, end, index, value);
    tree[node] = (tree[node*2] * tree[node*2 + 1]) % DIV;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> U >> Q;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    
    int root = 1, start = 1, end = N;
    init(root, start, end);

    for (int i = 0; i < U + Q; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) update(root, start, end, b, c);
        else if (a == 2) cout << query(root, start, end, b, c) << '\n';
    }

    return 0;
}
