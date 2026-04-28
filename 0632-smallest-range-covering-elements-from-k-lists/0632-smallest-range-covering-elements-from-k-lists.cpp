class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        
        // {value, list_index, element_index}
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> minHeap;
        
        int current_max = INT_MIN;
        
        // Initialize heap
        for (int i = 0; i < k; i++) {
            minHeap.push({nums[i][0], i, 0});
            current_max = max(current_max, nums[i][0]);
        }
        
        int range_start = 0, range_end = INT_MAX;
        
        while (true) {
            auto [val, list_idx, elem_idx] = minHeap.top();
            minHeap.pop();
            
            // Update best range
            if (current_max - val < range_end - range_start) {
                range_start = val;
                range_end = current_max;
            }
            
            // Move to next element in the same list
            if (elem_idx + 1 == nums[list_idx].size()) break;
            
            int next_val = nums[list_idx][elem_idx + 1];
            minHeap.push({next_val, list_idx, elem_idx + 1});
            
            current_max = max(current_max, next_val);
        }
        
        return {range_start, range_end};
    }
};