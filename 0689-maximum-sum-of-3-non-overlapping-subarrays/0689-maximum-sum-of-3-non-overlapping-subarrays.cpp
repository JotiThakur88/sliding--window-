#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // Step 1: Compute window sums
        vector<int> w(n - k + 1);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (i >= k) sum -= nums[i - k];
            if (i >= k - 1) w[i - k + 1] = sum;
        }

        int m = w.size();

        // Step 2: Best left index
        vector<int> left(m);
        int best = 0;
        for (int i = 0; i < m; i++) {
            if (w[i] > w[best]) best = i;
            left[i] = best;
        }

        // Step 3: Best right index
        vector<int> right(m);
        best = m - 1;
        for (int i = m - 1; i >= 0; i--) {
            if (w[i] >= w[best]) best = i; // >= ensures lexicographically smallest
            right[i] = best;
        }

        // Step 4: Try middle window
        vector<int> ans(3, 0);
        int maxSum = 0;

        for (int j = k; j < m - k; j++) {
            int i = left[j - k];
            int l = right[j + k];

            int total = w[i] + w[j] + w[l];

            if (total > maxSum) {
                maxSum = total;
                ans = {i, j, l};
            }
        }

        return ans;
    }
};