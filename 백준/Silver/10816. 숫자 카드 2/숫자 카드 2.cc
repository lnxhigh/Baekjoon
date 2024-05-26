#include <bits/stdc++.h>
#define N_MAX 500000
using namespace std;

int N, M;
int card, cards[N_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> cards[i];
    sort(cards, cards + N);
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> card;
        int lwr = lower_bound(cards, cards + N, card) - cards;
        int upr = upper_bound(cards, cards + N, card) - cards;
        int cnt = upr - lwr;
        cout << cnt << " ";
    }
    cout << "\n";
    
    return 0;
}
