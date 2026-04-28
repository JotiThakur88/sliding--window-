class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> isFlipped(n, 0);
        
        int flip = 0;   // current flip parity
        int ans = 0;

        for (int i = 0; i < n; i++) {
            
            // remove flip effect when window passes
            if (i >= k) {
                flip ^= isFlipped[i - k];
            }

            // if current bit after flips is 0 → must flip
            if ((nums[i] ^ flip) == 0) {
                
                // can't flip (out of bounds)
                if (i + k > n) return -1;

                ans++;
                flip ^= 1;
                isFlipped[i] = 1;
            }
        }

        return ans;
    }
};