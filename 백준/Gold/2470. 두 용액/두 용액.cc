#include <iostream>
#include <algorithm>
#include <stdlib.h>

#define MAX 100000

using namespace std;

int N;
int arr[MAX];

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+N);
    
    int start = 0, end = N-1;
    int _start = 0, _end = N-1;
    int m = abs(arr[start] + arr[end]);
    int x;

    while (start < end) {
        x = arr[start] + arr[end];
        if (abs(x) < m) {
            _start = start; _end = end;
            m = abs(x);
        }

        if (x < 0) { start++; }
        else if (x > 0) { end--; }
        else { break; }
    }

    cout << arr[_start] << ' ' << arr[_end];

    return 0;
}