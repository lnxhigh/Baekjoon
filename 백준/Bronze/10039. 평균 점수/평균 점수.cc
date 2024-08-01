#include <bits/stdc++.h>
using namespace std;

const int N = 5;
int score;
int ans = 0;

int main() {
    for (int i = 0; i < N; i++) {
       cin >> score;
       ans += max(score, 40); 
    }
    ans /= N;
    cout << ans << '\n';
    
    return 0; 
}
