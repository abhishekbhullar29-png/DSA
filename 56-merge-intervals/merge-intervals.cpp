class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};

        // Sort intervals by starting time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        // Add first interval
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // Check if intervals overlap
            if (start <= ans.back()[1]) {
                // Merge intervals
                ans.back()[1] = max(ans.back()[1], end);
            }
            else {
                // No overlap, add new interval
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};