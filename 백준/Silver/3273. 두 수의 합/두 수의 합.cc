#include <iostream>
#include <algorithm>
#define MAX 100000

using namespace std;

int N, x;
int arr[MAX];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int cnt = 0;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cin >> x;

    sort(arr, arr+N);

    if (x < arr[0] + arr[1] || x > arr[N-2] + arr[N-1]) {
        cout << cnt;
        return 0;
    }

    int start = 0, end = N-1;
    int sum = 0;
    
    while (start < end) {
        sum = arr[start] + arr[end];
        if (sum < x) { start++; }
        else if (sum > x) { end--; }
        else { cnt++; start++; end--; }
    }

    cout << cnt;

    return 0;
}