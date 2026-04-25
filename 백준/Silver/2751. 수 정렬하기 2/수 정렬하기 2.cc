#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;

int N;
int arr[MAX];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);

    for (int i = 0; i < N; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}