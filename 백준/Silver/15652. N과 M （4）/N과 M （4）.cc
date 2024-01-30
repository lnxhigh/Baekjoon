#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;

void backtrack(vector<int>& arr, int m, int depth) {
    if (depth == M) {
        for (int x : arr) {
            cout << x << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (i < m) continue;
        arr.push_back(i);
        backtrack(arr, i, depth+1);
        arr.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> M;
    backtrack(arr, 0, 0);

    return 0;
}