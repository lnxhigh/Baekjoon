#include <bits/stdc++.h>
#define N_MAX 100001
using namespace std;

int T;
int DVD[N_MAX];
int tree[2][N_MAX << 2];
enum FUNC { MIN, MAX };

int init(int node, int start, int end, int f) {
    if (start == end) return tree[f][node] = DVD[start];
    
    int mid = (start + end) / 2;
    int leftInit = init(node*2, start, mid, f);
    int rightInit = init(node*2 + 1, mid+1, end, f);
    return tree[f][node] = f ? max(leftInit, rightInit) : min(leftInit, rightInit);
}

int query(int node, int start, int end, int left, int right, int f) {
    if (end < left || start > right) return f ? 0 : 1 << 20;
    if (left <= start && end <= right) return tree[f][node];

    int mid = (start + end) / 2;
    int leftQuery = query(node*2, start, mid, left, right, f);
    int rightQuery = query(node*2 + 1, mid+1, end, left, right, f);
    return f ? max(leftQuery, rightQuery) : min(leftQuery, rightQuery);
}

void update(int node, int start, int end, int index, int value, int f) {
    if (index < start || index > end) return;
    if (start == end) {
        tree[f][node] = value;
        return;
    }

    int mid = (start + end) / 2;
    update(node*2, start, mid, index, value, f);
    update(node*2 + 1, mid+1, end, index, value, f);
    
    int leftUpdate  = tree[f][node*2];
    int rightUpdate = tree[f][node*2 + 1];
    tree[f][node] = f ? max(leftUpdate, rightUpdate) : min(leftUpdate, rightUpdate);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        fill(DVD, DVD + N_MAX, 0);
        fill(&tree[0][0], &tree[1][N_MAX-1] + 1, 0);
        for (int i = 1; i <= N; i++) DVD[i] = i;

        int root = 1, start = 1, end = N;
        for (int f = 0; f < 2; f++) init(root, start, end, f);
        
        for (int k = 0; k < K; k++) {
            int Q, A, B;
            cin >> Q >> A >> B;
            ++A; ++B;
            if (Q) {
                int min_value = query(root, start, end, A, B, FUNC::MIN);
                int max_value = query(root, start, end, A, B, FUNC::MAX);

                bool res = (min_value == A) && (max_value == B);
                string answer = res ? "YES" : "NO";
                cout << answer << '\n';
            }
            else {
                int tmpA = DVD[A], tmpB = DVD[B];
                DVD[A] = tmpB; DVD[B] = tmpA;
                for (int f = 0; f < 2; f++) {
                    update(root, start, end, A, tmpB, f);
                    update(root, start, end, B, tmpA, f);
                }
            }
        }
    }

    return 0;
}
