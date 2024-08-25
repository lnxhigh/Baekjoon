#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 1 << 10;
bool D[MAX];
vector<int> C = { 1, 3, 4 };

int main() {
    cin >> N;
    
    for (int k : C) {
        D[k] = true;
    }

    for (int i = 5; i <= N; i++) {
        for (int k : C) {
            D[i] |= !D[i-k]; 
        }
    }

    string winner = D[N] ? "SK" : "CY";
    cout << winner << '\n';
    return 0;
}
