#include <bits/stdc++.h>
using namespace std;

void Backtracking (int target, int start_idx, vector <int> &nums, vector <vector<int>> &res, vector <int> &path) {
    if (target == 0) { //Target reached -> Save current valid path
        res.push_back (path);
        return;
    }
    if (target < 0) return; //Target exceeded (negative) -> Prune this branch immediately
    for (int i=start_idx; i<nums.size(); i++) {
        path.push_back (nums[i]);
        // Pass 'i', (not i + 1) to allow reusing the same element
        // Pass (target - nums[i]) directly without modifying the local target variable (target = target - nums[i])
        Backtracking (target-nums[i], i, nums, res, path);
        path.pop_back ();
    }
}

vector <vector<int>> All_combinations (vector <int> &nums, int target) {
    vector <int> path;
    vector <vector<int>> res;
    Backtracking (target, 0, nums, res, path);
    return res;
}

int main () {
    int n, target;
    cin >> n >> target;
    vector <int> nums (n);
    for (int i=0; i<nums.size(); i++) cin >> nums[i];
    vector <vector<int>> Result = All_combinations (nums, target);
    for (int i=0; i<Result.size(); i++) {
        cout << "[";
        for (int j=0; j<Result[i].size(); j++) {
            cout << Result[i][j];
            if (j+1 < Result[i].size()) cout << " ";
        }
        cout << "] ";
    }
    return 0;
}