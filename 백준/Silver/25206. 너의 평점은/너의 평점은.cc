#include <bits/stdc++.h>
using namespace std;

const int N = 20;
unordered_map<string,double> gradePoint = {
    {"A+", 4.5}, {"A0", 4.0},
    {"B+", 3.5}, {"B0", 3.0}, 
    {"C+", 2.5}, {"C0", 2.0},
    {"D+", 1.5}, {"D0", 1.0}, 
    {"F", 0.0 },
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    double sum = 0.0;
    double total = 0.0;
    for (int i = 0; i < N; i++) {
        string subject;
        double credit;
        string grade;

        cin >> subject >> credit >> grade;

        if (grade == "P") continue;
        sum += credit * gradePoint[grade];
        total += credit;
    }

    double gpa = sum / total;
    cout << setprecision(16) << gpa << '\n';
    return 0;
}
