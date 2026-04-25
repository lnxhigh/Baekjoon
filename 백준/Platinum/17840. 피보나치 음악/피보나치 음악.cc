#include <iostream>
#include <string>
#define ll long long

using namespace std;

int Q, M;
ll N;
ll cnt = 0LL;
int temp = 0, previous = 0, next_ = 1;
bool dp[1001][1001] = {false,};
int fibo[1001*1001] = {0, 1, };
string seq = "";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> Q >> M;

    while (dp[previous][next_] == 0) {
        dp[previous][next_] = true;
        temp = next_;
        next_ = (next_ + previous) % M;
        previous = temp;
        cnt++;
    }

    for (int i = 2; i < cnt; i++) {
        fibo[i] = (fibo[i-1] + fibo[i-2]) % M; 
    }
    
    int periodicity = 0;
    for (int i = 0; i < cnt; i++) {
        string s = to_string(fibo[i]);
        seq += s;
        periodicity += s.size();
    }

    for (int i = 0; i < Q; i++) {
        cin >> N;
        N %= periodicity;
        cout << seq[N] << '\n';
    }

    return 0;
}
