#include <iostream>
using namespace std;

int N, S;
int arr[20];
int sum = 0, cnt = 0;

void f(int i) {
    if (i == N) {
        if (sum == S) { cnt++; }
        return;
    }
    f(i+1);
    sum += arr[i];
    f(i+1);
    sum -= arr[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    f(0);
    if (S == 0) { cnt--; }
    cout << cnt;

    return 0;
}
