#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> negatives, ones, positives;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;

        // Divide groups into three
        vector<int> &V = (X <= 0) ? negatives : (X <= 1) ? ones : positives;
        V.push_back(X);
    }

    int res = 0;
    vector<vector<int>> vectors = { negatives, positives }; 

    for (vector<int> &V : vectors) {
        // Multiply large numbers
        sort(V.begin(), V.end(), [] (int &x, int &y) { return abs(x) > abs(y); });
        
        // Pad identity
        int size = V.size();
        if (size % 2 == 1) V.push_back(1);

        // Update sum
        for (int i = 0; i < size; i += 2) {
            res += V[i] * V[i+1];
        }
    }

    // Add ones
    res += ones.size();

    // Result
    cout << res << '\n';
    return 0;
}
