class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int, int>> dq; // {x, y-x}
        int ans = INT_MIN;

        for (auto& p : points) {
            int x = p[0], y = p[1];

            // Remove points out of range (xj - xi > k)
            while (!dq.empty() && x - dq.front().first > k) {
                dq.pop_front();
            }

            // Use best candidate
            if (!dq.empty()) {
                ans = max(ans, dq.front().second + y + x);
            }

            // Maintain decreasing order of (y - x)
            while (!dq.empty() && dq.back().second <= y - x) {
                dq.pop_back();
            }

            dq.push_back({x, y - x});
        }

        return ans;
    }
};