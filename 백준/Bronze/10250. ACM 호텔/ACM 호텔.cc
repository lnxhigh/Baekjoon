#include <iostream>
#include <iomanip>
using namespace std;

int T;
int H, W, N;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> H >> W >> N;
        N--;
        cout << N % H + 1 << setfill('0') << setw(2) << N / H + 1 << '\n';
    }
    return 0;
}
