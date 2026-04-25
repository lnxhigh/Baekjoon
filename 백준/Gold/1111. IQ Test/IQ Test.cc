#include <iostream>
#include <string>
using namespace std;

int N;
int arr[50];

int main(void) {
    cin >> N;
    if (N == 1) {
        cin >> arr[0];
        cout << 'A';
        return 0;
    }
    
    else if (N == 2) {
        cin >> arr[0] >> arr[1];
        if (arr[0] == arr[1]) {
            cout << arr[0];
            return 0;
        }
        else {
            cout << 'A';
            return 0;
        }
    }

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    if (arr[0] == arr[1]) {
        for (int i = 2; i < N; i++) {
            if (arr[i] != arr[0]) {
                cout << 'B';
                return 0;
            }
        }
        cout << arr[0];
        return 0;
    }
    
    int a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
    int b = arr[1] - arr[0] * a;
    
    for (int i = 2; i < N; i++) {
        if (arr[i] != arr[i-1]*a + b) {
            cout << 'B';
            return 0;
        }
    }
    cout << arr[N-1]*a + b;
    return 0;
}