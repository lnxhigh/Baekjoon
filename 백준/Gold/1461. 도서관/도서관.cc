#include <bits/stdc++.h>
using namespace std;

int N, M;
const int MAX = 1 << 6;
int books[MAX];
vector<int> pos, neg;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> books[i];
        vector<int> &V = (books[i] > 0) ? pos : neg;
        V.push_back(books[i]);
    }
    
    int res = 0, last = 0;
    vector<vector<int>> Vs = { pos, neg };

    for (auto V : Vs) {
        sort(V.begin(), V.end(), [] (int &x, int &y) { return abs(x) > abs(y); });
        for (int k : V) { last = max(last, abs(k)); }
        for (int i = 0; i < V.size(); i += M) { res += abs(V[i]) * 2; }
    }

    res -= last;
    cout << res << '\n';
    return 0;
}
