#include <iostream>

using namespace std;

int N;
int inorder[100001];
int postorder[100001];

void f(int inorder[], int postorder[], int n) {
    if (n == 0) { return; }
    int root = postorder[n-1];
    int pivot = 0;

    for (int i = 0; i < n; i++) {
        if (inorder[i] == root) {
            pivot = i;
            break;
        }
    
    }
    cout << root << ' ';
    f(inorder, postorder, pivot);
    f(inorder + pivot + 1, postorder + pivot, n - pivot - 1);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> inorder[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> postorder[i];
    }

    f(inorder, postorder, N);
}
