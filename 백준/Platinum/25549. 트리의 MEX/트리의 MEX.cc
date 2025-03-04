#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int MAX = 200001;

int N;
int P[MAX], V[MAX];

int D[MAX];
int T[MAX];
set<int> S[MAX];
int MEX[MAX];

int main() {
    FastIO
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> V[i];
    }

    for (int i = 1; i <= N; i++) {
        if (P[i] != -1) D[P[i]]++;
        T[i] = i;
        S[i].insert(V[i]);
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (D[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        while (S[T[x]].find(MEX[x]) != S[T[x]].end()) MEX[x]++;
        if (P[x] == -1) continue;

        if (--D[P[x]] == 0) q.push(P[x]);
        MEX[P[x]] = max(MEX[P[x]], MEX[x]);

        // Small to Large Trick
        if (S[T[P[x]]].size() >= S[T[x]].size()) {
            for (auto e : S[T[x]]) S[T[P[x]]].insert(e);
        }
        else {
            for (auto e : S[T[P[x]]]) S[T[x]].insert(e);
            T[P[x]] = T[x]; // Change pointer
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << MEX[i] << '\n';
    }

    return 0;
}
