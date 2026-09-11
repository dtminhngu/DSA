// Find the maximum sum of k consecutive elements in the array
#include <bits/stdc++.h>
using namespace std;

int Max_Sum_SubArray (vector <int> &arr, int k) {
    int current_sum = 0;
    int max_sum = 0;
    for (int i=0 ;i<k; i++) current_sum += arr[i];
    max_sum = current_sum;

    for (int i=k; i<arr.size(); i++) {
        current_sum = current_sum + arr[i] - arr[i-k];
        max_sum = max (max_sum, current_sum);
    }
    return max_sum;
}

int main () {
    int n,k;
    cin >> n >> k;
    vector <int> arr (n);
    for (int i=0; i<arr.size(); i++) cin >> arr[i];
    cout << Max_Sum_SubArray (arr, k) << endl;
    return 0;
}