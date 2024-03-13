#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;

    for (int i = 0; i < N / 4; i++) {
        cout << "long ";
    }
    cout << "int\n";
    
    return 0;
}