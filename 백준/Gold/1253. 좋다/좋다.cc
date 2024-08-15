#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 1 << 11;
int A[MAX];

unordered_map<int,int> counts;
unordered_map<int,bool> isGood;

// naive solution => check TLE

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    // deal with exception of zero ...
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (A[i] != 0 && A[j] != 0) isGood[A[i] + A[j]] = true;;
        }
    }

    // save counts
    for (int i = 0; i < N; i++) {
        counts[A[i]]++;
    }

    // handle zero
    int zeros = counts[0];
    if (zeros > 2) isGood[0] = true;
    
    if (zeros > 0) {
        for (int i = 0; i < N; i++) {
            if (A[i] != 0 && counts[A[i]] > 1) isGood[A[i]] = true;
        }
    }

    // get result
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (isGood[A[i]]) cnt++;
    }

    cout << cnt << '\n';
    return 0;
}
