#include <iostream>
using namespace std;

int preorder[10000];
int N = 0, key = 0;

void postorder(int* arr, int len) {
    if (len == 0) return;
    
    int root = arr[0];
    int m = len;
    for (int i = 1; i < len; i++) {
        if (arr[i] > root) {
            m = i; 
            break;
        }
    }

    postorder(arr + 1, m-1);
    postorder(arr + m, len - m);
    cout << root << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    while (cin >> key) {
        preorder[N++] = key;    
    }
    postorder(preorder, N);

    return 0;
}