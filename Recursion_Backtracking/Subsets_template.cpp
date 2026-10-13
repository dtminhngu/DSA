#include <bits/stdc++.h>
using namespace std;

/* 
 * - start_idx: Ensures forward-only traversal to avoid duplicate subsets (e.g., [1,2] vs [2,1])
 * - nums: Input datas
 * - current_path: Temporary container representing the current state/branch in the decision tree
 * - res: Final container holding all valid generated subsets
 */

// Helper function for Backtracking (DFS)
 void backtrack(int start_idx, vector<int>& nums, vector<int>& current_path, vector<vector<int>>& res) {    
    // Base state / Collection step: 
    // In the 'Subsets' pattern, every node in the recursion tree represents a valid subset.
    res.push_back(current_path);

    // Iterate through all remaining valid choices
    for (int i = start_idx; i < nums.size(); ++i) {
        // Step 1: CHOOSE (Try adding the current element to our path)
        current_path.push_back(nums[i]);
        // Step 2: EXPLORE (Recursively move deeper to the next index)
        backtrack(i + 1, nums, current_path, res);
        // Step 3: UN-CHOOSE / BACKTRACK (Undo the choice to clean up current_path before the next iteration)
        current_path.pop_back();
    }
}


// Main function to generate all subsets
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> current_path;
    
    // Starting backtracking process from index 0
    backtrack(0, nums, current_path, res);
    
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < nums.size(); i++) cin >> nums[i];
    
    vector<vector<int>> all_subsets = subsets(nums);
    
    for (int i = 0; i < all_subsets.size(); i++) {
        cout << "[";
        for (int j = 0; j < all_subsets[i].size(); j++) {
            cout << all_subsets[i][j];
            if (j + 1 < all_subsets[i].size()) { //only print space " " if there are still elements behind
                cout << " ";
            }
        }
        cout << "]";
        cout << " ";
    }
    
    return 0;
}