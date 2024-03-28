#include <iostream>
using namespace std;

int T, N, M;
int answer = 1;

int choose(int n, int k) {
    int res = 1;
    if (k > n/2) k = n - k;
    
    for (int i = 0; i < k; i++) {
        res = res * (n-i) / (i+1);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> M;
        answer = choose(M, N); 
        cout << answer << '\n';
    }
}
