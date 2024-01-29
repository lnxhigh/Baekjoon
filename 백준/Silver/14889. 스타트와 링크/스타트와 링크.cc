#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int S[20][20];
int answer = 10000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }

    vector<int> bits;
    for (int bit = 0; bit < (1 << N); bit++) {
        int cnt = 0;
        for (int k = 0; k < N; k++) {
            if (bit & (1 << k)) cnt++;
        }
        if (cnt == N/2) bits.push_back(bit);
    }
    
    for (int bit : bits) {
        vector<int> start, link;
        for (int k = 0; k < N; k++) {
            if (bit & (1 << k)) start.push_back(k);
            else link.push_back(k);
        }
        
        int start_stat = 0, link_stat = 0;
        for (int i : start) {
            for (int j : start) {
                start_stat += S[i][j];
            }
        }
        for (int i : link) {
            for (int j : link) {
                link_stat += S[i][j];
            }
        }
        int value = abs(start_stat - link_stat);
        answer = min(answer, value);
    }

    cout << answer << '\n';

    return 0;
}