#include <iostream>
#include <algorithm>
#include <stack>
#define MAX 1001
using namespace std;

int N;
int arr[MAX] = {0,};
int dp[MAX] = {1,};
stack<int> value;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    for (int i = 1; i <= N; i++){
        for (int k = 1; k < i; k++){
            if(arr[k] < arr[i]){
                dp[i] = max(dp[i], dp[k] + 1);
            }
        }
    }

    int M = *max_element(dp+1, dp+1+N);
    cout << M << '\n';

    for (int i = N; i >= 1; i--) {
        if (dp[i] == M) {
            value.push(i);
            M--;
        }
    }
    
    while (not value.empty()) {
        cout << arr[value.top()] << ' ';
        value.pop();
    }

    return 0;
}