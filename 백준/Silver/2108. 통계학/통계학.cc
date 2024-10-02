#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int &X : A) cin >> X;

    // Mean

    int sum = accumulate(A.begin(), A.end(), 0);
    int cnt = N;

    int mean = round((double) sum / (double) cnt);

    // Median

    sort(A.begin(), A.end());
    int median = A[(N - 1) / 2];
    
    // Mode;

    unordered_map<int,int> M;
    for (int &X : A) M[X]++;

    int maxcnt = 0;
    for (const auto& [ i, cnt ] : M) {
        maxcnt = max(maxcnt, cnt);
    }

    vector<int> modes;
    for (const auto& [ i, cnt ] : M) {
        if (cnt == maxcnt) {
            modes.push_back(i);
        }
    }
    sort(modes.begin(), modes.end());

    int mode = (int) modes.size() <= 1 ? modes[0] : modes[1];

    // Range
    
    int range = A[(int) A.size() - 1] - A[0];

    // Result
    
    cout << mean << '\n';
    cout << median << '\n';
    cout << mode << '\n';
    cout << range << '\n';

    return 0;
}
