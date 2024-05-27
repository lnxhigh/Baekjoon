#include <bits/stdc++.h>
#define N_MAX 1000001
#define ll long long
using namespace std;

// 틀리는 이유를 도저히 모르겠음 ...

int N, U, Q;
ll arr[N_MAX];
ll tree[N_MAX << 2];

ll init(int node, int start, int end) {
    int mid = (start + end) / 2;
    if (start == end) return tree[node] = arr[mid];
    
    ll leftValue = init(node*2, start, mid);
    ll rightValue = init(node*2 + 1, mid + 1, end);
    return tree[node] = leftValue + rightValue;
}

ll query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0LL;
    if (left <= start && end <= right) return tree[node];
    
    ll mid = (start + end) / 2;
    ll leftQuery = query(node*2, start, mid, left, right);
    ll rightQuery = query(node*2 + 1, mid+1, end, left, right);
    return leftQuery + rightQuery;
}

void update(int node, int start, int end, int index, ll diff) {
    if (index < start || index > end) return;
    
    tree[node] += diff;
    if (start == end) return;

    ll mid = (start + end) / 2;
    update(node*2, start, mid, index, diff);
    update(node*2 + 1, mid+1, end, index, diff);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> U >> Q;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    init(1, 0, N-1);

    int T = U + Q;
    for (int i = 0; i < T; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 0, N-1, b-1, c - arr[b-1]);
            arr[b-1] = c;
        }
        else if (a == 2) cout << query(1, 0, N-1, b-1, c-1) << '\n';
    }
    
    return 0;
}
