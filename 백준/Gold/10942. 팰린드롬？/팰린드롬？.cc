#include <iostream>
#define N_MAX 2000
using namespace std;

int N, M;
int S, E;
int numbers[N_MAX];
bool isPalindrome[N_MAX][N_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    for (int i = 0; i < N; i++) {
        isPalindrome[i][i] = true;
    }
    for (int i = 0; i < N-1; i++) {
        isPalindrome[i][i+1] = (numbers[i] == numbers[i+1]);
    }
    for (int len = 3; len <= N; len++) {
        for (int start = 0; start < N-2; start++) {
            int end = start + len - 1;
            isPalindrome[start][end] = (
                isPalindrome[start+1][end-1] and 
                numbers[start] == numbers[end]
            );
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> S >> E;
        S--; E--;
        cout << isPalindrome[S][E] << '\n';
    }

    return 0;
}