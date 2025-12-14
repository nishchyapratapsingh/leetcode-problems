class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        sort(strs.begin(), strs.end());
        string start = strs[0];
        string end = strs[n-1];
        int nG = start.length()>end.length() ? end.length() : start.length();
        int i=0;
        while (i<nG && start[i] == end[i]) {
            i++;
        }
        return start.substr(0, i);
    }
};