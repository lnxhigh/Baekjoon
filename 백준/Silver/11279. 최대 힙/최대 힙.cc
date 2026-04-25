#include <iostream>
#include <queue>
#define MAX 100000

using namespace std;

int N;
int arr[MAX];
priority_queue< int, vector<int>, less<int> > pq;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) { cin >> arr[i]; }

    int x;
    for (int i = 0; i < N; i++) {
        x = arr[i];
        if (x == 0) {
            if (pq.empty()) { cout << 0 << '\n'; }
            else { cout << pq.top() << '\n'; pq.pop(); }
        }
        else { pq.push(x); }
    }

    return 0;
}