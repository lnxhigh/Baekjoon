#include <bits/stdc++.h>
using namespace std;

int problems[11] = {
    12, 11, 11, 10, 
    9, 9, 9, 8, 7, 6, 6
};

int panelties[11] = {
    1600, 894, 1327, 1311, 1004, 
    1178, 1357, 837, 1055, 556, 773
};

int main() {
    int N; cin >> N;
    --N;
    cout << problems[N] << ' ' << panelties[N] << '\n';
    return 0;
}
