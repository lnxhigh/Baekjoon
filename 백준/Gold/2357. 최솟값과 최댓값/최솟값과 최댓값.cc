#include <bits/stdc++.h>
#define N_MAX 100001
using namespace std;

int N, M;
int arr[N_MAX];
int tree[2][N_MAX << 2];
enum { MIN, MAX };

int init(int node, int start, int end, int f) {
    if (start == end) return tree[MIN][node] = tree[MAX][node] = arr[start];

    int mid = (start + end) / 2;
    int leftInit = init(node*2, start, mid, f);
    int rightInit = init(node*2 + 1, mid+1, end, f);

    if      (f == MIN) tree[f][node] = min(leftInit, rightInit);
    else if (f == MAX) tree[f][node] = max(leftInit, rightInit);
    return tree[f][node];
}

int query(int node, int start, int end, int left, int right, int f) {
    if (end < left || start > right) {
        if      (f == MIN) return 1 << 30;
        else if (f == MAX) return 0;
    }

    if (left <= start && end <= right) return tree[f][node];

    int mid = (start + end) / 2;
    int leftQuery = query(node*2, start, mid, left, right, f);
    int rightQuery = query(node*2 + 1, mid+1, end, left, right, f);

    int res;
    if      (f == MIN) res = min(leftQuery, rightQuery);
    else if (f == MAX) res = max(leftQuery, rightQuery);
    
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    
    int root = 1, start = 1, end = N;
    init(root, start, end, MIN);
    init(root, start, end, MAX);

    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        int min_value = query(root, start, end, a, b, MIN);
        int max_value = query(root, start, end, a, b, MAX);
        cout << min_value << " " << max_value << "\n";
    }

    return 0;
}
