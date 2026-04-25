#include <iostream>
#include <string>
#include <map>
#define SIZE 8
using namespace std;

int N;
string code[] = {"000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010"};
char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

int decode(char arr[]) {
    int miss[SIZE] = {0,};

    for (int i = 0; i < SIZE; i++) {
        for (int k = 0; k < 6; k++) {
            if (code[i][k] != arr[k]) {
                miss[i]++;
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {
        if (miss[i] == 0) {
            return i;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        if (miss[i] == 1) {
            return i;
        }
    }

    return -1;
}


int main(void) {
    cin >> N;
    std::cin.ignore();

    char arr[N][7] = {0,};
    char ans[N+1] = {0,};
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        int k = decode(arr[i]);
        if (k == -1) {
            cout << i + 1;
            return 0;
        }
        else {
            ans[i] = letters[k];
        }
    }

    cout << ans;
    return 0;
}