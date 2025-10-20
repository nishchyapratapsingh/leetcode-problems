class Solution {
public:
    char kthCharacter(int k) {
        string str;
        str.push_back('a');
        while (str.length() < k) {
            int n = str.length();
            for (int i=0; i<n; i++) {
                str.push_back(str[i]+1);
            }
        }
        cout<<str;
        return str[k-1];
    }
};