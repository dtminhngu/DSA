#include <bits/stdc++.h>
using namespace std;

void Try (int i, bool visited[100], vector <int> &nums, vector <int> &path, vector <vector<int>> &res) {
    if (i == nums.size()) {
        res.push_back (path);
        return;
    }

    for (int j=0; j<nums.size(); j++)  {
        if (!visited[j]) {
            path.push_back (nums[j]);
            visited[j] = true;
            Try (i+1, visited, nums, path, res);
            path.pop_back ();
            visited[j] = false;
        }
    }
}

vector <vector<int>> res (vector <int> &nums) {
    vector <int> path;
    vector <vector<int>> res;
    bool visited [100];
    Try (0, visited, nums, path, res);
    return res;
}

int main () {
    int n;
    cin >> n;
    vector <int> nums (n);
    for (int i=0; i<nums.size(); i++) cin >> nums[i];
    vector <vector<int>> outputs = res (nums);
    if (outputs.empty ()) cout << "-1\n";
    for (int i=0; i<outputs.size(); i++) {
        cout << "[";
        for (int j=0; j<outputs[i].size(); j++) {
            cout << outputs[i][j];
            if (j+1 < outputs[i].size()) cout << " ";
        }
        cout << "] ";
    }
    return 0;
}