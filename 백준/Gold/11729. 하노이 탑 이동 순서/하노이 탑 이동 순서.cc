#include <iostream>
using namespace std;

int N;

void hanoi(int N, int from, int auxi, int to) {
    if (N == 1) { 
        cout << from << ' ' << to << '\n'; 
        return; 
    }
    hanoi(N-1, from, to, auxi);
    cout << from << ' ' << to << '\n';
    hanoi(N-1, auxi, from, to);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    cout << (1 << N) - 1 << '\n';
    hanoi(N, 1, 2, 3);
    return 0;
}