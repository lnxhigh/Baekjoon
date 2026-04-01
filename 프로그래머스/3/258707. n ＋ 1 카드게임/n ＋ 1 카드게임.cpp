#include <bits/stdc++.h>

using namespace std;
const int MAX = 1024;

bool one[MAX];
bool other[MAX];

int solution(int coin, vector<int> cards) {
    int n = cards.size();
    int round = 0;
    
    for (int i = 0; i < n / 3; i++) {
        int card = cards[i];
        one[card] = true;
    }
    
    while (true) {
        round++;
        
        bool flag = false;
        int index = (n / 3) + (round - 1) * 2;
        
        // 뽑을 카드가 없으면 게임 끝
        if (index >= n) break;
    
        // 카드를 뽑는다
        int x = cards[index];
        int y = cards[index + 1];
        other[x] = other[y] = true;  
        
        // 카드를 낼 수 있다면 카드를 낸다
        for (int i = 1; i <= n and not flag; i++) {
            if (not one[i] or not one[n + 1 - i]) continue;
            one[i] = one[n + 1 - i] = false;
            flag = true;
        }

        // 동전을 하나 써서 카드를 낼 수 있다면 카드를 사서 낸다
        for (int i = 1; i <= n and coin >= 1 and not flag; i++) {
            if (not one[i] or not other[n + 1 - i]) continue;
            
            one[i] = other[n + 1 - i] = false;
            coin -= 1;
            flag = true;
        }
        
        // 동전을 두 개 써서 카드를 낼 수 있다면 카드를 사서 낸다
        for (int i = 1; i <= n and coin >= 2 and not flag; i++) {
            if (not other[i] or not other[n + 1 - i]) continue;
            
            other[i] = other[n + 1 - i] = false;
            coin -= 2;
            flag = true;
        }
        
        // 카드를 낼 수 없으면 게임 끝
        if (not flag) break;
    }

    return round;
}
