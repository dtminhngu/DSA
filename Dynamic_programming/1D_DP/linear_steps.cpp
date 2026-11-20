#include <bits/stdc++.h>
using namespace std;

int solve (int n) {
    // With n<=2, number of ways = n; tackle "out of bound" bug
    if (n<=2) return n;
    // 1. Def of dp[i]: number of distinct ways to reach the i-th step
    vector <int> dp (n+1);
    // 2. Base case
    dp[1] = 1; // 1->1
    dp[2] = 2; // 1 -> 2, 2->2
    // 3. Recursive formula
    for (int i=3; i<=n; i++) dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

int main () {
    int n;
    cin >> n;
    cout << solve (n);
    return 0;
}