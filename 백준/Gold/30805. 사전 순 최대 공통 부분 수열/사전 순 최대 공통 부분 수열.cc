#include <bits/stdc++.h>
using namespace std;
vector<int> A, B;

int find(int x, const vector<int> &V) {
    for (int i = 0; i < (int) V.size(); i++) {
        if (V[i] == x) return i;
    }
    return -1;
}

int main() {
    int N; cin >> N; A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int M; cin >> M; B.resize(M);
    for (int i = 0; i < M; i++) cin >> B[i];

    vector<int> res;
    int largest = 100;

    while (largest) {
        // Find largest common element
        int i = find(largest, A);
        int j = find(largest, B);

        // If there is no largest element
        // decrease the value and try to find again
        if (i == -1 || j == -1) { largest--; continue; }

        // Save the element as a result if there is a common element
        res.push_back(largest);

        // Keep doing this for the rest of the elements
        A.erase(A.begin(), A.begin() + i + 1);
        B.erase(B.begin(), B.begin() + j + 1);
    }

    cout << res.size() << '\n';
    for (int x : res) cout << x << ' ';
    cout << '\n';
    return 0;
}
