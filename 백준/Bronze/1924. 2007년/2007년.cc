#include <bits/stdc++.h>
using namespace std;

int M, D;
int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string week[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

int main() {
    cin >> M >> D;
    int diff = D;
    for (int i = 0; i < M; i++) diff += days[i];
    cout << week[diff % 7];
    return 0;
}
