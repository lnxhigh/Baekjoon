#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
using xy = pair<int,int>;

ostream& operator<< (ostream& os, const xy& p) {
    os << p.first << " " << p.second;
    return os;
}

int N;
xy arr[100000];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    int x, y;

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        arr[i] = {x,y};
    }
    sort(arr, arr+N);

    for (int i = 0; i < N; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}