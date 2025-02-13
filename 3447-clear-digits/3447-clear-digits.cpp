class Solution {
public:
    string clearDigits(string s) {
        int j=0; 

        for (char c: s) {
            if(isdigit(c)) {
                if (j>0) j--;
            }

            else {
                s[j++] = c;
            }
        }

        return s.substr(0,j);
    }
};