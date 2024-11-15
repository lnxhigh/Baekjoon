#include <bits/stdc++.h>
using namespace std;

enum { WIN, DRAW, LOSE };
double P[4][4][3];

int A[6] = { 0, 0, 0, 1, 1, 2 };
int B[6] = { 1, 2, 3, 2, 3, 3 };

int R[6];
double X[6];

void dfs(int depth) {
    if (depth == 6) {
        double p = 1.0;
        pair<double,int> Y[4] = { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 } };

        for (int i = 0; i < 6; i++) {
            int a = A[i], b = B[i];
            p *= P[a][b][R[i]];

            int sa = (R[i] == WIN) ? 3 : (R[i] == LOSE) ? 0 : 1;
            int sb = (R[i] == WIN) ? 0 : (R[i] == LOSE) ? 3 : 1;
            Y[a].first += sa, Y[b].first += sb;
        }

        sort(Y, Y + 4);
    
        // 상위 두 팀이 결정적으로 정해지는 경우
        if (Y[1].first < Y[2].first) {
            X[Y[3].second] += p;
            X[Y[2].second] += p;
        }
        
        // 상위 두 팀이 확률적으로 정해지는 경우
        else {
            // 1등이 결정적으로 정해지는 경우
            if (Y[2].first < Y[3].first) {
                X[Y[3].second] += p;
                
                int cnt = 0;
                for (int i = 0; i < 3; i++) {
                    if (Y[i].first == Y[2].first) {
                        cnt++;
                    }
                }

                for (int i = 0; i < 3; i++) {
                    if (Y[i].first == Y[2].first) {
                        X[Y[i].second] += p / cnt;
                    }
                }
            }

            // 1등이 확률적으로 정해지는 경우
            else {
                int cnt = 0;
                for (int i = 0; i < 4; i++) {
                    if (Y[i].first == Y[3].first) {
                        cnt++;
                    }
                }
                for (int i = 0; i < 4; i++) {
                    if (Y[i].first == Y[3].first) {
                        X[Y[i].second] += p * 2.0 / cnt;
                    }
                }
            }
        }

        return;
    }

    for (int i : { WIN, DRAW, LOSE }) {
        R[depth] = i;
        dfs(depth + 1);
    }
}

int main() {
    map<string,int> name;
    for (int i = 0; i < 4; i++) {
        string S; cin >> S;
        name[S] = i;
    }

    for (int i = 0; i < 6; i++) {
        string sa, sb; cin >> sa >> sb;
        double win, draw, lose;
        cin >> win >> draw >> lose;

        int a = name[sa], b = name[sb];
        P[a][b][WIN] = P[b][a][LOSE] = win;
        P[a][b][DRAW] = P[b][a][DRAW] = draw;
        P[a][b][LOSE] = P[b][a][WIN] = lose;
    }

    dfs(0);

    cout << fixed << setprecision(16);
    for (int i = 0; i < 4; i++) {
        cout << X[i] << '\n';
    }

    return 0;
}
