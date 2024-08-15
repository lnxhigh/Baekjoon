#include <bits/stdc++.h>
using namespace std;

int N, X;
const int MAX = 1 << 11;
int A[MAX];

// Two Pointers
bool IsGood(int k) {
    int target = A[k];
    int first = 0, last = N-1;

    while (first < last) {
        bool self = (first == k) || (last == k);
        if (self) {
            if (first == k) first++;
            if (last  == k) last-- ;
            continue;
        }

        int sum = A[first] + A[last];

        if (sum < target) first++;
        else if (sum > target) last--;
        else return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A, A + N);
    for (int i = 0; i < N; i++) {
        if (IsGood(i)) X++;
    }

    cout << X << '\n';
    return 0;
}
