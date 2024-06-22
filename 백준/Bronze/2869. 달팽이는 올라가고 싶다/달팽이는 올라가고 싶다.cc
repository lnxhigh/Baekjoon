#include <bits/stdc++.h>

int main() {
    int A, B, V;
    std::cin >> A >> B >> V;
    std::cout << ( V - B - 1 ) / ( A - B ) + 1 << '\n';
    return 0;
}
