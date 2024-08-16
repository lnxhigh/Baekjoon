#include <bits/stdc++.h>
using namespace std;

long long S;

int main() {
    cin >> S;
    long long X = (-1.0 + sqrt(1 + 8*S)) / 2.0;
    cout << X << '\n';
    return 0;
}
