//Find shortest subarray that sum of its element >= target
#include <bits/stdc++.h>
using namespace std;

int Min_length (vector <int> &nums, int target) {
    int left = 0, sum = 0;
    int min_length = INT_MAX;
    for (int right = 0; right < nums.size(); right ++) {
        //Extend the window by adding elements 
        sum += nums[right];
        // if sum >= target, subtract nums[left] from the window and move left pointer to the right
        while (sum >= target) {
            //window size = last - first + 1
            min_length = min (min_length, right-left+1); // compare min_length and window size to get minimum length
            sum -= nums[left];
            left ++;    
        }
    }
    if (min_length == INT_MAX) return 0;
    else return min_length;
}

int main () {
    int n,target;
    cin >> n >> target;
    vector <int> nums (n);
    for (int i=0; i<nums.size(); i++) cin >> nums[i];
    cout << Min_length (nums, target) << endl;
    return 0;
}