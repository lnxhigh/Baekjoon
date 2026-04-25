#include <iostream>
#include <utility>
#include <algorithm>
#define MAX 100000
using namespace std;
using xy = pair<int,int>;

int N, x, y;
xy arr[MAX];

ostream& operator<< (ostream& os, const xy& p) {
    os << p.first << " " << p.second;
    return os;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        arr[i] = {x,y};
    }
    sort(arr, arr+N, [](xy a, xy b){
        if (a.second < b.second) return true;
        else if (a.second > b.second) return false;
        else {
            if (a.first < b.first) return true;
            else return false;
        }
    });

    for (int i = 0; i < N; i++) {
        cout << arr[i] << '\n';
    }
    return 0;
}