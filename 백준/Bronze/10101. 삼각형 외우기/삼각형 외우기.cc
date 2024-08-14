#include <bits/stdc++.h>
using namespace std;

string solve(int x, int y, int z) {
    if (x + y + z != 180) return "Error";
    
    if (x == y && y == z && z == x) return "Equilateral";
    else if (x == y || y == z || z == x) return "Isosceles";
    else return "Scalene";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int x, y, z;
    cin >> x >> y >> z;
    cout << solve(x, y, z) << '\n';

    return 0;
}
