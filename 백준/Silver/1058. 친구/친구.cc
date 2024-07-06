#include <bits/stdc++.h>
using namespace std;

int N;
const int N_MAX = 50;
bool isFriend[N_MAX][N_MAX];
bool isTwoFriend[N_MAX][N_MAX];
int numTwoFriend[N_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char letter;
            cin >> letter;
            isFriend[i][j] = (letter == 'Y');
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!isFriend[i][j]) continue;
            
            isTwoFriend[i][j] = true;
            for (int k = 0; k < N; k++) {
                if (isFriend[j][k] && i != k) isTwoFriend[i][k] = true;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (isTwoFriend[i][j]) numTwoFriend[i]++;
        }
    }

    int res = *max_element(numTwoFriend, numTwoFriend + N);    
    cout << res << '\n';
    return 0;
}
