#include <iostream>
using namespace std;

int x = 0;
int check = 0;

int main(void) {
    ios::sync_with_stdio(false);
    for (int i = 0; i < 5; i++) {
        cin >> x; 
        check += x*x;
    }
    cout << check % 10 << '\n';
}