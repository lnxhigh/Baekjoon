#include <bits/stdc++.h>
using namespace std;

const int MAX = 1 << 4;
vector<int> V;

void print(int A[MAX], int N, int idx) {
    int cnt = V.size();
    if (cnt == 6) {
        for (int i : V) cout << A[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = idx; i < N; i++) {
        V.push_back(i);
        print(A, N, i+1);
        V.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (true) {
        int K;
        cin >> K;
        if (K == 0) break;

        int S[MAX];
        for (int k = 0; k < K; k++) cin >> S[k];

        print(S, K, 0);
        V.clear();
        cout << '\n';
    }

    return 0;
}
