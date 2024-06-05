#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

string S, P;
int F[MAX];

int main() {
    getline(cin, S); getline(cin, P);
    int N = S.size(), M = P.size();

    for (int i = 1, k = 0; i < M; i++) {
        while (k > 0 && P[i] != P[k]) k = F[k-1];
        if (P[i] == P[k]) F[i] = ++k;
    }

    vector<int> res;
    for (int i = 0, k = 0; i < N; i++) {
        while (k > 0 && S[i] != P[k]) k = F[k-1];
        if (S[i] == P[k]) k++;
        if (k == M) { 
            res.push_back(i+1-k); 
            k = F[k-1]; 
        }
    }

    cout << res.size() << '\n';
    for (int i : res) cout << i+1 << ' ';
    cout << '\n';
    return 0;
}
