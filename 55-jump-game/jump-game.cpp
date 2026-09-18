class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        for (int i = 0; i < nums.size(); i++) {
            // If current index cannot be reached
            if (i > farthest)
                return false;

            // Update the farthest index we can reach
            farthest = max(farthest, i + nums[i]);

            // Already reached the last index
            if (farthest >= nums.size() - 1)
                return true;
        }

        return true;
    }
};