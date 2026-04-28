#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Count frequency
        for (int num : nums) {
            freq[num]++;
        }

        int maxLen = 0;

        // Check pairs
        for (auto &p : freq) {
            int x = p.first;

            if (freq.count(x + 1)) {
                maxLen = max(maxLen, freq[x] + freq[x + 1]);
            }
        }

        return maxLen;
    }
};