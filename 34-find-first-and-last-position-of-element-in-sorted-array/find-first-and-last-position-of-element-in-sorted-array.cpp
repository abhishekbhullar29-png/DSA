class Solution {
public:
    int firstPosition(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                answer = mid;
                right = mid - 1; // Search further left
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return answer;
    }

    int lastPosition(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                answer = mid;
                left = mid + 1; // Search further right
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return answer;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {
            firstPosition(nums, target),
            lastPosition(nums, target)
        };
    }
};