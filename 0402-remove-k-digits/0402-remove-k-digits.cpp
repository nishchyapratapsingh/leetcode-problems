class Solution {
public:
     string removeKdigits(string nums, int k) {

    	int n = nums.size();
    	string s;
        s.push_back(nums[0]);
    	for (int i = 1; i < n; i++) {
    		while (!s.empty() && s.back() > nums[i] && k>0) {
    			s.pop_back();
    			k--;
    		}
    		s.push_back(nums[i]);
    	}

        while (k--) {
            s.pop_back();
        }

        int i = 0;
        while (i < s.size() && s[i] == '0') {
            i++;
        }

        s = s.substr(i);

        return s.empty() ? "0" : s;
    }
};