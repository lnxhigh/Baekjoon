#include <iostream>
#include <algorithm>
#define N_MAX 100000
#define INF 2147483647
using namespace std;

int N;
int arr[N_MAX];
int value = INF;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+N);

    int start = 0, end = N-1;
    int start_, end_;
    int sum = 0;

    while (start < end) {
        sum = arr[start] + arr[end];

        if (abs(sum) < value) {
            start_ = start;
            end_ = end;
            value = abs(sum);
        }

        if (sum > 0) end--;
        else if (sum < 0) start++;
        else break;

    }

    cout << arr[start_] << ' ' << arr[end_] << '\n';
    
    return 0;
}