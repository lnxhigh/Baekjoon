#include <iostream>
using namespace std;

int T, N;
int primeList[10001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    primeList[0] = false;
    primeList[1] = false;
    for (int i = 2; i <= 10000; i++) {
        primeList[i] = true;
    }

    for (int i = 2; i <= 10000; i++) {
        if (primeList[i]) {
            for (int k = 2*i; k <= 10000; k = k+i) {
                primeList[k] = false;
            }
        }
    }

    for (int i = 0; i < T; i++) {
        cin >> N;

        int x = N / 2;
        int y = N / 2;
        
        while (true) {
            if (primeList[x] and primeList[y]) {
                cout << x << ' ' << y << '\n';
                break;
            }    
            else {
                x -= 1; 
                y += 1;
            }
        }
    }

    return 0;
}
