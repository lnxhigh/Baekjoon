#include <iostream>
#include <algorithm>
#define N_MAX 100001
#define SCORE_MAX 1000001
using namespace std;

int N;
int player, card;
int cards[N_MAX];
int score[N_MAX] = {0,};
int cardToPlayer[SCORE_MAX] = {0,};
int playerToCard[N_MAX] = {0,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    for (player = 1; player <= N; player++) {
        cin >> card;
        cardToPlayer[card] = player;
        playerToCard[player] = card;
        cards[player] = card;
    }
    
    sort(cards+1, cards+1+N);

    for (int i = 1; i <= N; i++) {
        int x = cards[i];
        for (card = x+x; card <= cards[N]; card = card+x) {
            if (cardToPlayer[card]) {
                score[cardToPlayer[x]]++;
                score[cardToPlayer[card]]--;
            }
        }
    }

    for (player = 1; player <= N; player++) {
        cout << score[player] << '\n';
    }

    return 0;
}