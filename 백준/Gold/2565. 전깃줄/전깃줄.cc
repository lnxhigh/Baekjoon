#include <iostream>
#include <utility>
#include <algorithm>
#include <set>
#define N_MAX 100001
#define LOC_MAX 500001
using namespace std;

int N;
int A[LOC_MAX] = {0,};
int B[LOC_MAX] = {0,};
pair<int,int> AB[N_MAX];
multiset<int> Aset;
multiset<int> Bset;

int X[N_MAX];
int P[N_MAX];
int M[N_MAX+1];
int S[N_MAX];
int L = 0;

// Longest Increasing Subsequence
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        A[a] = b, B[b] = a;
        AB[i] = {a,b};
        Aset.insert(a); Bset.insert(b);
    }

    sort(AB, AB + N);
    for (int i = 0; i < N; i++) {
        X[i] = AB[i].second;
    }

    // LIS
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

        if (low > L) L = low;
    }

    int k = M[L];
    for (int i = L-1; i >= 0; i--) {
        S[i] = X[k];
        k = P[k];
    }
    
    cout << N - L << '\n';

    return 0;
}