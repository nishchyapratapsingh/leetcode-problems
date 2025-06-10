class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> vec;
        for(auto in: intervals){
            if(vec.empty() || vec.back()[1]<in[0]) vec.push_back(in);
            else vec.back()[1]=max(vec.back()[1], in[1]);
        }
        return vec;
    }
};