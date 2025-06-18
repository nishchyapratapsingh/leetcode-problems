class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i += 3) {
            if (i + 2 >= nums.size()) return {}; 

            vector<int> group = {nums[i], nums[i+1], nums[i+2]};
            
            if (group[2] - group[0] > k) return {}; 
            result.push_back(group); 
        }
        
        return result;
    }
};
