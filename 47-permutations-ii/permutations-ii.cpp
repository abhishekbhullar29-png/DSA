class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current) {
        // If permutation is complete
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            // Already used
            if (used[i])
                continue;

            // Skip duplicate numbers
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            used[i] = true;
            current.push_back(nums[i]);

            backtrack(nums, used, current);

            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<bool> used(nums.size(), false);
        vector<int> current;

        backtrack(nums, used, current);

        return result;
    }
};