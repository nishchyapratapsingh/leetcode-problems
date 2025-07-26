class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> nge; 
        stack<int> st; 

        for (int x : nums2) {
            while (!st.empty() && x > st.top()) {
                nge[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }

        while (!st.empty()) {
            nge[st.top()] = -1;
            st.pop();
        }
        
        vector<int> res;
        for (int x : nums1) {
            res.push_back(nge[x]);
        }
        return res;
    }
};
