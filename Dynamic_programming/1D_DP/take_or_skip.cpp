#include <bits/stdc++.h>
using namespace std;

int solve (vector <int> &nums) {
    // 1. dp[i] -> max amount of money you can rob from house 0->house i
    int n = nums.size();
    vector <int> dp (n);
    if (n==1) return nums[0];
    // 2. Base case
    dp[0] = nums[0];
    dp[1] = max (nums[0], nums[1]);
    // 3. Recursive formula
    // dp[i-1] -> max amount of money you can rob frorm house 0 -> house i-1 (skip house i)
    // nums[i] + dp[i-2] -> rob money from house i, plus max amount of money rob from house 0 -> house i-2 (take house i)
    for (int i=2; i<n; i++) dp[i] = max (nums[i] + dp[i-2], dp[i-1]);
    return dp[n-1];
}

int main () {
    int n;
    cin >> n;
    vector <int> nums (n);
    for (int i=0; i<n; i++) cin >> nums[i];
    cout << solve (nums);
    return 0;
}