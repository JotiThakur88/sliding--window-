#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        return helper(s, 0, s.size(), k);
    }

private:
    int helper(string &s, int start, int end, int k) {
        if (end - start < k) return 0;

        vector<int> freq(26, 0);

        // Count frequency
        for (int i = start; i < end; i++) {
            freq[s[i] - 'a']++;
        }

        // Check for invalid characters
        for (int mid = start; mid < end; mid++) {
            if (freq[s[mid] - 'a'] < k) {
                // Split here
                int left = helper(s, start, mid, k);
                int right = helper(s, mid + 1, end, k);
                return max(left, right);
            }
        }

        // Whole substring is valid
        return end - start;
    }
};