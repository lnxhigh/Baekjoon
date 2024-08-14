#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 1 << 17;
int X[MAX], Y[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) { cin >> X[i] >> Y[i]; }
    
    int W = *max_element(X, X + N) - *min_element(X, X + N);
    int H = *max_element(Y, Y + N) - *min_element(Y, Y + N);
    cout << W * H << '\n';
    return 0;
}
