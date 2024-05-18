#include <bits/stdc++.h>
#define N_MAX 100000
#define M_MAX 100000
using namespace std;

int N, M;
int arr[N_MAX];

int search(int arr[], int N, int target) {
    int s = 0, e = N-1;
    while (s <= e) {
        int m = s + (e - s) / 2;
        int value = arr[m];
        if (target > value) s = m + 1;
        else if (target < value) e = m - 1;
        else return 1;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    cin >> M;
    for (int i = 0; i < M; i++) {
        int target;
        cin >> target;
        cout << search(arr, N, target) << '\n';
    }
    
    return 0;
}
