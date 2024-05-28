#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int N;
int A[MAX];
int tree[MAX << 2];
int ROOT = 1, START = 1, END = MAX - 1;

int query(int node, int start, int end, int left, int right) {
    if (end < left || start > right) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    int leftQuery = query(node*2, start, mid, left, right);
    int rightQuery = query(node*2 + 1, mid+1, end, left, right);
    return leftQuery + rightQuery;
}

void update(int node, int start, int end, int index, int value) {
    if (index < start || index > end) return;
    if (start == end) {
        tree[node] = value;
        return;
    }

    int mid = (start + end) / 2;
    update(node*2, start, mid, index, value);
    update(node*2 + 1, mid+1, end, index, value);
    tree[node] = tree[node*2] + tree[node*2 + 1];
}

int search(int r) {
    int res;
    int start = 1, end = MAX - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        int sum = query(ROOT, START, END, START, mid);

        if (sum >= r) {
            res = mid;
            end = mid - 1;
        }
        else {
            start = mid+1;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a;
        if (a == 1) {
            cin >> b;
            int c = search(b);
            cout << c << '\n';
            A[c]--;
            update(ROOT, START, END, c, A[c]);
        }
        else if (a == 2) {
            cin >> b >> c;
            A[b] += c;
            update(ROOT, START, END, b, A[b]);
        }
    }

    return 0;
}
