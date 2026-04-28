#include <string>
using namespace std;

class Solution {
public:
    bool queryString(string s, int n) {
        for (int i = n; i >= 1; i--) {
            string b = toBinary(i);
            if (s.find(b) == string::npos) {
                return false;
            }
        }
        return true;
    }

private:
    string toBinary(int num) {
        string res = "";
        while (num > 0) {
            res = char('0' + (num % 2)) + res;
            num /= 2;
        }
        return res;
    }
};