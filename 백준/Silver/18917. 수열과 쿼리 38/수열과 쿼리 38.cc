#include <iostream>
#define ll long long
using namespace std;

ll M;  
ll query, x;
ll sum = 0LL, xor_ = 0LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> M;
    for (ll m = 0; m < M; m++) {
        cin >> query;
        if (query == 1) {
            cin >> x;
            sum += x;
            xor_ ^= x;
        }
        else if (query == 2) {
            cin >> x;
            sum -= x;
            xor_ ^= x;
        }
        else if (query == 3) {
            cout << sum << '\n';
        }
        else if (query == 4) {
            cout << xor_ << '\n';
        }
    }
    
    return 0;
}