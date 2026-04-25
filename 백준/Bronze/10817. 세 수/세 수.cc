#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int x, y, z;
    cin >> x >> y >> z;
    int nums[3] = { x,y,z };
    sort(nums, nums+3);
    cout << nums[1] << '\n';
    return 0;
}