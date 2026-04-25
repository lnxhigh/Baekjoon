#include <iostream>
#include <string>
using namespace std;

int scale[8];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    for (int i = 0; i < 8; i++) {
        cin >> scale[i];
    }
    
    int start = scale[0];
    bool ascending = true, descending = true, mixed = true;
    string state;
    
    for (int i = 0; i < 7; i++) {
        if (scale[i] > scale[i+1]) ascending = false;
        else descending = false;
    }
    if (ascending or descending) mixed = false;

    if (ascending) state = "ascending";
    else if (descending) state = "descending";
    else state = "mixed";

    cout << state << '\n';
}
