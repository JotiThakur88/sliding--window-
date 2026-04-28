class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxD, minD;
        int left = 0, ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            
            // maintain max deque (decreasing)
            while (!maxD.empty() && nums[right] > maxD.back()) {
                maxD.pop_back();
            }
            maxD.push_back(nums[right]);

            // maintain min deque (increasing)
            while (!minD.empty() && nums[right] < minD.back()) {
                minD.pop_back();
            }
            minD.push_back(nums[right]);

            // shrink window if invalid
            while (maxD.front() - minD.front() > limit) {
                if (nums[left] == maxD.front()) maxD.pop_front();
                if (nums[left] == minD.front()) minD.pop_front();
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};