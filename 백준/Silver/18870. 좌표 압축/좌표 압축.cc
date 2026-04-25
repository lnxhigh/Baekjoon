#include <iostream>
#include <algorithm>
#include <map>
#define MAX 1000000
using namespace std;

int N;
int arr[MAX];
int arr_sort[MAX];
map<int,int> rank_;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr_sort[i] = arr[i];
    }

    sort(arr_sort, arr_sort+N);

    int k = 0;
    for (int i = 0; i < N; i++) {
        if (not rank_.count(arr_sort[i])) {
            rank_[arr_sort[i]] = k;
            k++;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << rank_[arr[i]] << ' ';
    }

    return 0;
}