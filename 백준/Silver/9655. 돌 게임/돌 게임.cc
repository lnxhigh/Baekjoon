#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    cin >> N;
    string winner = N & 1 ? "SK" : "CY";
    cout << winner << '\n';
    return 0;
}
