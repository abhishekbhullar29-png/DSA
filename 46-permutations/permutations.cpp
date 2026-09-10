class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, vector<int>& current, vector<bool>& used) {
        // If current permutation has all elements
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }

        // Try every unused number
        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;

            // Choose
            used[i] = true;
            current.push_back(nums[i]);

            // Explore
            backtrack(nums, current, used);

            // Undo choice
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        vector<bool> used(nums.size(), false);

        backtrack(nums, current, used);

        return ans;
    }
};