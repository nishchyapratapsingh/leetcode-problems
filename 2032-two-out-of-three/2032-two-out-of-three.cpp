class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> freq;

        unordered_set<int> s1;
        for (int x : nums1) {
            freq[x] = 1;
            s1.insert(x);
        }

        unordered_set<int> s2;
        for (int x : nums2) {
            if (s1.count(x)) {
                freq[x] = 2;
            }
            else {
                freq[x] = 1;
                s2.insert(x);
            }
        }

        for (int x : nums3) {
            if (s1.count(x) && s2.count(x)) {
                freq[x] = 3;
            }
            else if (s1.count(x) || s2.count(x)) {
                freq[x] = 2;
            }
            else freq[x] = 1;
        }

        vector<int> ans;

        for (auto &it : freq) {
            if (it.second >= 2) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};