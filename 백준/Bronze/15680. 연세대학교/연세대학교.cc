#include <iostream>
using namespace std;

int N;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    
    if (N == 0) {
        cout << "YONSEI";
    }
    else {
        cout << "Leading the Way to the Future";
    }
    cout << '\n';
    
    return 0;
}