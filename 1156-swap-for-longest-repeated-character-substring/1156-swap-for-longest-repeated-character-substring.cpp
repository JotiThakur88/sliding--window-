#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxRepOpt1(string text) {
        vector<int> freq(26, 0);
        for (char c : text) freq[c - 'a']++;

        int n = text.size();
        int result = 0;

        // Try for each character
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int left = 0, count = 0;

            for (int right = 0; right < n; right++) {
                if (text[right] == ch) count++;

                // Window size - matching chars > 1 → more than 1 mismatch
                while ((right - left + 1) - count > 1) {
                    if (text[left] == ch) count--;
                    left++;
                }

                // Limit by total frequency
                result = max(result, min(freq[ch - 'a'], right - left + 1));
            }
        }

        return result;
    }
};