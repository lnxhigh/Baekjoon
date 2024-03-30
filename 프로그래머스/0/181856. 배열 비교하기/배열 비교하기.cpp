#include <bits/stdc++.h>
using namespace std;

int compare(vector<int> &left, vector<int> &right) {
    int l = left.size(), r = right.size();
    if (l > r) return 1;
    else if (l < r) return -1;
    else {
        int sumLeft = 0, sumRight = 0;
        for (int i = 0; i < (l+r)/2; ++i) {
            sumLeft  += left[i];
            sumRight += right[i];
        }
        if (sumLeft > sumRight) return 1;
        else if (sumLeft < sumRight) return -1;
        else return 0;
    }
    return 0;
}

int solution(vector<int> arr1, vector<int> arr2) {
    return compare(arr1, arr2);
}