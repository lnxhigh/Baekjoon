#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N;
const int N_MAX = 40;
pair<int,int> Points[N_MAX];

double area(int i, int j, int k) {
    int X1 = Points[i].X - Points[k].X;
    int Y1 = Points[i].Y - Points[k].Y;
    int X2 = Points[j].X - Points[k].X;
    int Y2 = Points[j].Y - Points[k].Y;

    double res = abs(X1 * Y2 - X2 * Y1) * 0.5;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        Points[i] = { A, B };
    }

    double maxArea = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                maxArea = max(maxArea, area(i, j, k));
            }
        }
    }

    cout << setprecision(16);
    cout << maxArea << '\n';
    return 0;
}
