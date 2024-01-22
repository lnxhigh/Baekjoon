#include <iostream>
#define N_MAX 1000000
using namespace std;

// https://en.wikipedia.org/wiki/Longest_increasing_subsequence

int N;
int X[N_MAX];
int P[N_MAX];
int M[N_MAX+1];
int L = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    M[0] = -1, M[1] = 0;

    for (int i = 0; i < N; i++) {
        int low = 1;
        int high = L + 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (X[M[mid]] >= X[i]) high = mid;
            else low = mid + 1;
        }
        
        P[i] = M[low-1];
        M[low] = i;

        if (low > L) {
            L = low;
        }
    }
    
    cout << L << '\n';
    
    return 0;
}