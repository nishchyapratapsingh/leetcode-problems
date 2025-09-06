class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        
        size_t pos = haystack.find(needle);
        return pos == string::npos ? -1 : (int)pos;
    }
};