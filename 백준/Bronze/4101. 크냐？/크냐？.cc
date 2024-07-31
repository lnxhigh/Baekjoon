#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (true) {
        int x, y;
        cin >> x >> y;
        if (x == 0 && y == 0) break;
        
        string s = (x > y) ? "Yes" : "No";
        cout << s << '\n';
    }
    
    return 0;
}
