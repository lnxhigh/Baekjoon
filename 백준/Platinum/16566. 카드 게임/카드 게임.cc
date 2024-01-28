#include <iostream>
#define N_MAX 4000001
#define M_MAX 4000001
#define K_MAX 10001
using namespace std;

int N, M, K;
int cards[N_MAX+1];
int parent[N_MAX+1];
int cheolsu[K_MAX];
int minsu[K_MAX];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (x < y) parent[x] = y;
    else parent[y] = x;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    // Init
    for (int i = 0; i < N_MAX+1; i++) {
        cards[i] = 0;
        parent[i] = i;
    }

    // Input
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        cards[num] = 1;
    }
    for (int i = 0; i < K; i++) {
        cin >> cheolsu[i];
    }

    // Process
    for (int i = 0; i <= N; i++) {
        if (cards[i]) continue;
        merge(i, i+1);
    }

    for (int i = 0; i < K; i++) {
        int k = find(cheolsu[i] + 1);
        if (k == N+1) {
            int m = find(0);
            minsu[i] = m;
            merge(m, m+1);
        }
        else {
            minsu[i] = k;
            merge(k, k+1);
        }
    }    

    for (int i = 0; i < K; i++) {
        cout << minsu[i] << '\n';
    }

    return 0;
}
