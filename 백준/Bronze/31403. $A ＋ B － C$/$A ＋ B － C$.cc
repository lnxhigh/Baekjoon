#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    cout << A + B - C << '\n';
    for (int i = B; i; i /= 10) A *= 10;
    cout << A + B - C << '\n';
    return 0;
}
