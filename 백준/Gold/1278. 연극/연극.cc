#include <bits/stdc++.h>
#define FastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;

int f(int x)
{
    return x ^ (x >> 1); // gray code
}

int _log(int x)
{
    int cnt = 0;
    while (x)
        cnt++, x >>= 1;
    return --cnt;
}

int main()
{
    FastIO;
    cin >> n;

    int cnt = (1 << n) - 1;
    cout << cnt << '\n';

    for (int i = 0; i < cnt; i++)
    {
        int x = f(i);
        int nxt = f(i + 1);
        int diff = _log(x ^ nxt);
        cout << ++diff << '\n';
    }
    cout << n << '\n';

    return 0;
}
