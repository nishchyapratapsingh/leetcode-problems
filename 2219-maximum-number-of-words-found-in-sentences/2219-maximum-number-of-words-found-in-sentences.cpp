class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi=INT_MIN;
        for(string str: sentences) {
            int count=1;
            for (int i=1; i<str.length(); i++) {
                if (str[i]==' ') {
                    count++;
                }
            }
            maxi = max(count, maxi);
        }
        return maxi;
    }
};