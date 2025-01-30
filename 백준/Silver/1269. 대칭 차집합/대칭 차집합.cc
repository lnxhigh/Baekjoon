#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 200001;

int M, N; 
int D[MAX];

int find(int x) {
    int low = 0, high = M;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (D[mid] < x) low = mid + 1;
        else if (D[mid] > x) high = mid - 1;
        else return mid;
    }
    return -1;
}

int main() {
    FastIO
    cin >> M >> N;
    for (int i = 0; i < M; i++) cin >> D[i];
    sort(D, D + M);
    
    int cnt = M;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        int idx = find(x);
        if (idx == -1) cnt++;
        else cnt--;
    }

    cout << cnt << '\n';
    return 0;
}
