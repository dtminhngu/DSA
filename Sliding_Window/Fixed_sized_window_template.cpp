// Find the maximum sum of k consecutive elements in the array
#include <bits/stdc++.h>
using namespace std;

int Max_Sum_SubArray (vector <int> &arr, int k) {
    //1. Create the first window with the size of k, calculate the sum of first k elements
    int current_sum = 0;
    int max_sum = 0;
    for (int i=0 ;i<k; i++) current_sum += arr[i];
    max_sum = current_sum;
    //2. Slide the window from index k to the end of the array
    for (int i=k; i<arr.size(); i++) {
        current_sum = current_sum + arr[i] - arr[i-k]; // update current_sum
        max_sum = max (max_sum, current_sum); //compare max_sum and current_sum to get maximum result
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