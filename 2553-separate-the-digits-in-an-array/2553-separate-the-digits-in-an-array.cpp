class Solution {
private: 
    void f(int num, vector<int> &ans) {
        vector<int> temp;
        while(num) {
            temp.push_back(num % 10);
            num/=10;
        }
        for (int i = temp.size()-1; i >= 0; i--) {
            ans.push_back(temp[i]);
        }
    }
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int num:nums) {
            f(num, ans);
        }

        return ans;
    }
};