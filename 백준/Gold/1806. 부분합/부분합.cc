#include <iostream>
#define N_MAX 100000
#define INF 100001
using namespace std;

int N, S;
int arr[N_MAX];
int answer = INF;
int Min(int x, int y) { return x < y ? x : y ; }

/*
이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중
가장 짧은 것의 길이를 구하는 프로그램
첫째 줄에 N (10 ≤ N < 100,000)과 S (0 < S ≤ 100,000,000)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int start = 0, end = 0;
    int len = 0;
    int sum = 0;


    while (true) {
        sum += arr[end++];
        len++;
        if (sum >= S) break;
        if (end == N) break;
    }
    end--; 
    
    if (end == N-1) {
        if (sum < S) {
            cout << 0 << '\n';
            return 0;
        }
    }

    sum -= arr[end--];
    len--;

    while (end < N-1) {
        sum += arr[++end];
        len++;
        while (true) {
            sum -= arr[start++];
            len--;
            if (sum < S) {
                sum += arr[--start];
                len++;
                break;
            }
        }
        answer = Min(answer, len);
    }
    
    cout << answer << '\n';

    return 0;
}