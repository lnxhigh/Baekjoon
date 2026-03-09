#include <string>
#include <vector>

using namespace std;

int f(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int cnt = 0;
    long long t1 = f(h1, m1, s1);
    long long t2 = f(h2, m2, s2);

    for (int k = 0; k <= 24 * 60; k++) {
        int x = k * 3600;
        bool chk = (x >= t1 * 59) && (x <= t2 * 59);
        if (chk) cnt++;
    }

    for (int k = 0; k <= 24 * 120; k++) {
        int x = k * 43200;
        bool chk = (x >= t1 * 719) && (x <= t2 * 719);
        if (chk) cnt++;
    }

    int x = 12 * 60 * 60;
    bool chk = (x >= t1) && (x <= t2);
    if (chk) cnt--;
    if (t1 == 0) cnt--;

    return cnt;
}
