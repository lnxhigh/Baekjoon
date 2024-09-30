#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int N;
int arr[MAX] = {0,};
int dp[MAX] = {1,};

int main() {
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
    cout << M;
}