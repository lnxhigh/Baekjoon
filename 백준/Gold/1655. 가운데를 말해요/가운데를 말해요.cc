#include <bits/stdc++.h>
using namespace std;

int N, X;
const int N_MAX = 1 << 17;
int A[N_MAX];

priority_queue< int, vector<int>, less<int>    > L;
priority_queue< int, vector<int>, greater<int> > R;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X;
        if (i % 2 == 0) { L.push(X); }
        else            { R.push(X); }

        while (!L.empty() && !R.empty()) {
            int leftTop  = L.top();
            int rightTop = R.top();
            if (leftTop <= rightTop) break;

            L.pop(); R.pop();
            L.push(rightTop); R.push(leftTop);
        }

        while (!L.empty() && !R.empty()) {
            int leftSize  = L.size();
            int rightSize = R.size();

            int diff = leftSize - rightSize;
            if (diff >= 0 && diff <= 1) break;

            if      (diff > 1) { R.push(L.top()); L.pop(); }
            else if (diff < 0) { L.push(R.top()); R.pop(); }
        }

        cout << L.top() << '\n';
    }

    return 0;
}
