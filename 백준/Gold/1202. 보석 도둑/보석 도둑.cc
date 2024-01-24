#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#define N_MAX 300001
#define K_MAX 300001
using namespace std;

int N; // The number of jewel
int M[N_MAX]; // M = weight
int V[N_MAX]; // V = value

int K; // The number of bags
int C[K_MAX]; // Capacity

pair<int,int> jewels[N_MAX]; // V, M pair
multiset<int> bags;
long long answer = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> M[i] >> V[i];
        jewels[i] = { V[i], M[i] };
    }
    for (int i = 0; i < K; i++) {
        cin >> C[i];
        bags.insert(C[i]);
    }
    
    sort(jewels, jewels + N);

    for (int i = N-1; i >= 0; i--) {
        int price = jewels[i].first;
        int capacity = jewels[i].second;

        auto it = bags.lower_bound(capacity);
        if (it == bags.end()) continue;

        answer += price;
        bags.erase(it);
    }
    cout << answer << '\n';

    return 0;
}