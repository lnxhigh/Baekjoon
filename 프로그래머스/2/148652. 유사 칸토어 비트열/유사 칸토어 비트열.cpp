#include <string>
#include <vector>

using namespace std;

bool f(long long x, int n) {
    if (n == 0) return true;
    bool flag = f(x / 5, n - 1);
    if (!flag) return 0;
    return (x % 5) != 2;
}

int solve(int n, long long l, long long r) {
    long long m = (l + r) / 2;
    if (l == r) return f(m, n);
    
    int x = solve(n, l, m);
    int y = solve(n, m + 1, r);
    return x + y;
}

int solution(int n, long long l, long long r) {
    l--, r--;
    return solve(n, l, r);
}
