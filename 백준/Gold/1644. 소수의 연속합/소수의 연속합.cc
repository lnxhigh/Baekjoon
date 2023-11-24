#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define N_MAX 4000001
using namespace std;

int N;
vector<int> prime;
vector<bool> isPrime(N_MAX, true);

int findMaxK(int N) {
    
    int k = 0;
    int sum = 0;
    while (true) {
        sum += prime[k];
        k++;
        if (sum > N) return --k;
    }
}

bool consecutive(int N, int k) {
    int x = floor((N * 1.0) / (k * 1.0));
    int mid = lower_bound(prime.begin(), prime.end(), x) - prime.begin();

    int start = mid - k/2;
    int end = mid + k/2;

    if (k % 2 == 0) start += 1;
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += prime[i];
    }

    if (sum < N) {
        while (true) {
            if (end >= prime.size()-1) return false;
            sum -= prime[start];
            start++;
            end++;
            sum += prime[end];
            if (sum == N) return true;
            if (sum > N) return false;
        }
    }
    else if (sum > N) {
        while (true) {
            if (start <= 0) return false;
            sum -= prime[end];
            end--;
            start--;
            sum += prime[start];
            if (sum == N) return true;
            if (sum < N) return false;
        }
    }
    else return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= N_MAX; i++) {
        if (not isPrime[i]) continue;
        for (int j = i*2; j <= N_MAX; j = j+i) {
            isPrime[j] = false;
        }
    }

    for (int i = 0; i < N_MAX; i++) {
        if (isPrime[i]) prime.push_back(i);
    }

    cin >> N;
    int K =  findMaxK(N);
    int answer = 0;

    for (int k = 1; k <= K; k++) {
        answer += consecutive(N, k);
    }
    cout << answer;
    
    return 0;
}