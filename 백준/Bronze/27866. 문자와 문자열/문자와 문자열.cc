#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string String;
    int index;
    cin >> String >> index;
    cout << String[index-1] << '\n';
    return 0;
}