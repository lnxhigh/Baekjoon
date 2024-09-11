#include <bits/stdc++.h>
using namespace std;

int y1_, m1, d1; 
int y2, m2, d2;
int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool IsLeap(int year) {
    if (year % 400 == 0) return true;
    else if (year % 100 == 0) return false;
    else if (year % 4 == 0) return true;
    return false;
}

int f(int year, int month, int day) {
    int res = 0;

    // year
    for (int i = 1; i < year; i++) {
        int all = 365;
        if (IsLeap(i)) all++;
        res += all;
    }

    // month
    bool isLeap = IsLeap(year);
    for (int i = 1; i < month; i++) {
        res += days[i];
    }
    if (isLeap && month > 2) res++;

    // day
    res += day;

    return res;
}

int solve(int y1_, int m1, int d1, int y2, int m2, int d2) {
    if (y2 - y1_ > 1000) return -1;
    else if (y2 - y1_ == 1000) {
        if (m2 > m1 || (m2 == m1 && d2 >= d1)) return -1;
    }

    int res = f(y2, m2, d2) - f(y1_, m1, d1);
    return res;
}

int main() {
    cin >> y1_ >> m1 >> d1;
    cin >> y2 >> m2 >> d2;
    int res = solve(y1_, m1, d1, y2, m2, d2);

    if (res == -1) cout << "gg" << '\n';
    else cout << "D-" << res << '\n';
    return 0;
}
