#include <bits/stdc++.h>
#define N_MAX 1000
using namespace std;

int N;
int arr[N_MAX];
int cumsum[N_MAX+1] = {0,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    for (int i = 0; i < N; i++) {
        cumsum[i+1] = cumsum[i] + arr[i];
    }
    
    int answer = 0;
    for (int i = 0; i <= N; i++) {
        answer += cumsum[i];
    }

    cout << answer << '\n';
    
    return 0;
}