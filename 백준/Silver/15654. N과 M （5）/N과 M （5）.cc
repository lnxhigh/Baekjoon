#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10];
int temp[10];

bool promising(int num, int next) {
    if (next == 0) {
        return true;
    }
    for (int i = 0; i < next; i++) {
        if (num == temp[i]) {
            return false;
        }
    }
    return true;
}

void print(int num, int next) {
    if (next == M and num == 0) {
        for (int i = 0; i < M; i++) {
            cout << arr[temp[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    if (promising(num, next)) {
        temp[next] = num;
        for (int i = 0; i < N; i++) {
            print(i, next+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+N);

    for (int i = 0; i < N; i++) {
        print(i, 0);
    }

    return 0;
}