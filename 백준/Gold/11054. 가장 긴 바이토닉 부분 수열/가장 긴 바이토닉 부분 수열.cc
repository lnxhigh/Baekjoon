#include <iostream>
#include <algorithm>
#define INF 2147483647
#define MAX 1001
using namespace std;

int N;
int arr[MAX] = {0,};
int dp[MAX] = {1,};
int A[MAX] = {0,};
int B[MAX] = {0,};

void LIS(int dp[], int arr[], int x[]) {
    for (int i = 1; i <= N; i++) {
        dp[i] = 1;
    }

    for (int i = 1; i <= N; i++){
        for (int k = 1; k < i; k++){
            if(arr[k] < arr[i]){
                dp[i] = max(dp[i], dp[k] + 1);
            }
        }
    }

    int len = 0;    
    for (int i = 1; i <= N; i++) {
        len = max(len, dp[i]);
        x[i] = len;
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    
    LIS(dp, arr, A);
    reverse(arr+1, arr+N+1);
    LIS(dp, arr, B);
    
    int ans = 1;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, A[i] + B[N+1-i] - 1);   
    }
    cout << ans;
}
