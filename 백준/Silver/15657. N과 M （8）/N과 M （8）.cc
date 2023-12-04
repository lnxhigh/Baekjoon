#include <iostream>
#include <algorithm>
#define N_MAX 10000
using namespace std;

int N, M;
int arr[N_MAX];
int seq[N_MAX];

bool promising(int cnt, int i) {
    if (cnt == 0) return true;
    return seq[cnt-1] <= arr[i];
}

void print(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << seq[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        if (promising(cnt, i)) {
            seq[cnt] = arr[i];
            print(cnt+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;

    for (int i = 0 ; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+N);
    print(0);

    return 0;
}
