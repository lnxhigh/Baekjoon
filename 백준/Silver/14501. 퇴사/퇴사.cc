// Brute force - inefficient code ...
// WA: Off-by-one error
// Suppose we set schedule[20]
// In that case, if N = 15, N + 5 = 20 and schedule[20] does not exist

#include <bits/stdc++.h>
using namespace std;

int N;
int answer = 0;

int Time[30];
int Profit[30];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int day = 1; day <= N; day++) {
        cin >> Time[day] >> Profit[day];
    }

    for (int bit = 0; bit < (1 << N); bit++) {
        int schedule[30] = {0,};
        int result = 0;

        for (int day = 1; day <= N; day++) {
            bool on = bit & (1 << (day-1));
            if (not on) continue;

            int start = day;
            int end = start + Time[day] - 1;
            for (int i = start; i <= end; i++) {
                schedule[i]++;
            }
            result += Profit[day];
        }
        
        bool busy = false;
        for (int i = 1; i <= N; i++) {
            if (schedule[i] >= 2) busy = true;
        }
        for (int i = N+1; i <= N+5; i++) {
            if (schedule[i] >= 1) busy = true;
        }
        if (busy) continue;

        answer = max(answer, result);
    }
    
    cout << answer << '\n';
}