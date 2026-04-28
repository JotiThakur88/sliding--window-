class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        
        int base = 0;     // already satisfied
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                base += customers[i];
            }
        }
        
        int extra = 0, maxExtra = 0;
        
        // sliding window for grumpy customers
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 1) {
                extra += customers[i];
            }
            
            if (i >= minutes && grumpy[i - minutes] == 1) {
                extra -= customers[i - minutes];
            }
            
            maxExtra = max(maxExtra, extra);
        }
        
        return base + maxExtra;
    }
};