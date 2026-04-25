#include<bits/stdc++.h>
using namespace std;
using int128 = __uint128_t;

int main()
{
    int128 x = 1;
    int n, m; cin >> n >> m;
    m = min(m, n - m);

    for (int i = 0; i < m; i++) x *= (n - i), x /= (i + 1);

    stack<int> st;
    while (x) st.push(x % 10), x /= 10;
    while (!st.empty()) cout << st.top(), st.pop();
    return 0;
}
