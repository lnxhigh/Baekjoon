#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    
    vector<int> ppl;
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    while (N--) {
        for (int i = 0; i < K-1; i++) {
            q.push(q.front());
            q.pop();
        }

        ppl.push_back(q.front());
        q.pop();
    }

    cout << '<';
    for (int i = 0; i < (int) ppl.size() - 1; i++) {
        cout << ppl[i] << ", ";
    }
    cout << ppl.back() << '>' << '\n';
    return 0;
}
