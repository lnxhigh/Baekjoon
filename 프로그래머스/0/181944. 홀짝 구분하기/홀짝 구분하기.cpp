#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    string s = N & 1 ? "odd" : "even" ;
    cout << N << " is " << s << '\n';
    return 0;
}