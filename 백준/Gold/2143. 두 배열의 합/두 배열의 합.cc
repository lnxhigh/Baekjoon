#include <iostream>
#include <algorithm>
using namespace std;

int T, n, m;
int A[1000], B[1000];
int Asum[1000][1000], Bsum[1000][1000];
int AA[1000000], BB[1000000];
int cntA = 0, cntB = 0;
int BinarySearch(int arr[], int len, int key, bool first);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> T;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        Asum[i][i] = A[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> B[i];
        Bsum[i][i] = B[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            Asum[i][j] = Asum[i][j-1] + Asum[j][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = i+1; j < m; j++) {
            Bsum[i][j] = Bsum[i][j-1] + Bsum[j][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            AA[cntA] = Asum[i][j];
            cntA++;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            BB[cntB] = Bsum[i][j];
            cntB++;
        }
    }

    sort(AA, AA+cntA);
    sort(BB, BB+cntB);
    
    long long ans = 0;

    for (int i = 0; i < cntA; i++) {
        int k1 = BinarySearch(BB, cntB, T-AA[i], true);
        if (k1 == -1) continue;
        int k2 = BinarySearch(BB, cntB, T-AA[i], false);

        ans += k2 - k1 + 1;
    }

    cout << ans << '\n';
    
    return 0;
}

int BinarySearch(int arr[], int len, int key, bool first) {
    int start = 0;
    int end = len-1;
    int mid;

    while (start <= end) {
        mid = (start+end) / 2;
        if (arr[mid] > key) {
            end = mid - 1;
        }
        else if (arr[mid] < key) {
            start = mid + 1;
        }
        else {
            if (first) {
                if (mid - 1 < 0 or arr[mid - 1] != key) return mid;
                else end = mid - 1;
            }
            else {
                if (mid + 1 > end or arr[mid + 1] != key) return mid;
                else start = mid + 1;
            }
        }
    }
    return -1;
}
