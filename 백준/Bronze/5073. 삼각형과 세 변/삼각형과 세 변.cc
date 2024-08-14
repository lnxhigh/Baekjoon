#include <bits/stdc++.h>
using namespace std;

string solve(int x, int y, int z) {
    if (x >= y + z || y >= z + x || z >= x + y) return "Invalid";
    
    if (x == y && y == z && z == x) return "Equilateral";
    else if (x == y || y == z || z == x) return "Isosceles";
    else return "Scalene";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x*x + y*y + z*z == 0) break;
        cout << solve(x, y, z) << '\n';
    }

    return 0;
}
