#include <bits/stdc++.h>
using namespace std;

string S;
int L;
int V[2];

int main() {
    cin >> S;
    int L = S.size();
    
    int cur = S[0];
    for (int i = 0; i < L; i++) {
        if (S[i] == cur) continue;
        V[cur - '0']++;
        cur = S[i];
    }
    V[cur - '0']++;

    cout << min(V[0], V[1]) << '\n';
    return 0;
}
