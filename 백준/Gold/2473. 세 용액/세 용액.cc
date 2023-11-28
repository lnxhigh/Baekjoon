#include <iostream>
#include <algorithm>
#define N_MAX 5000
#define ll long long
#define INF 3000000000LL
using namespace std;

int N;
ll arr[N_MAX];
ll Abs(ll x) { return x > 0LL ? x : -x ; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+N);
 
    int left = 0, mid = 1, right = N-1;
    int left_ = 0, mid_ = 1, right_ = N-1;
    ll sum = 0;
    ll ans = INF;

    for (mid = 1; mid <= N-2; mid++) {
        left = 0; right = N-1;
        
        while (left < mid and mid < right) {
            sum = arr[left] + arr[right] + arr[mid];
            if (ans > Abs(sum)) {
                ans = Abs(sum);
                left_ = left; mid_ = mid; right_ = right;
            }

            if (sum > 0) right--;
            else if (sum < 0) left++;
            else break;
        }
    }

    cout << arr[left_] << ' ' << arr[mid_] << ' ' << arr[right_] << '\n';
    
    return 0;
}
