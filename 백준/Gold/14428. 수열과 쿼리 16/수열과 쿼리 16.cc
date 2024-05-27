#include <bits/stdc++.h>
#define N_MAX 100001
using namespace std;

int N, M;
int A[N_MAX];
int tree[N_MAX << 2];

int f(int left, int right) {
    if (!left) return right;
    if (!right) return left;

    int res;
    if (A[left] < A[right]) res = left;
    else if (A[left] > A[right]) res = right;
    else res = (left <= right) ? left : right;
    return res;
}

int init(int node, int start, int end) {
    if (start == end) return tree[node] = start;

    int mid = (start + end) / 2;
    int leftInit  = init(node*2, start, mid);
    int rightInit = init(node*2 + 1, mid+1, end);

    return tree[node] = f(leftInit, rightInit);
}

int query(int node, int start, int end, int left, int right) {
    if (right < start || left > end) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    int leftQuery  = query(node*2, start, mid, left, right);
    int rightQuery = query(node*2 + 1, mid+1, end, left, right);

    return f(leftQuery, rightQuery);
}

void update(int node, int start, int end, int index, int value) {
    if (index < start || index > end) return;
    if (start == end) {
        tree[node] = index;
        return;
    }

    int mid = (start + end) / 2;
    update(node*2, start, mid, index, value);
    update(node*2 + 1, mid+1, end, index, value);
    tree[node] = f(tree[node*2], tree[node*2 + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    cin >> M;

    int root = 1, start = 1, end = N;
    init(root, start, end);

    for (int m = 1; m <= M; m++) {
        int p, i, j;
        cin >> p >> i >> j;
        if (p == 1) {
            A[i] = j;
            update(root, start, end, i, j);
        }
        else if (p == 2) {
            cout << query(root, start, end, i, j) << '\n';
        }

    }

    return 0;
}
