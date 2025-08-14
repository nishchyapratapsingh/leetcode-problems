class Solution {
public:
    string largestGoodInteger(string num) {

        int n=num.length();
        if (n<3) return "";
        string s;
        int i=0;
        int maxi = INT_MIN;

        while (i<n-1) {
            int c=1;
            while (num[i]==num[i+1]) {
                c++;
                i++;
            }
            if (c>=3) {
                maxi = max(maxi, num[i]-'0');
                i--;
            }
            i++;
        }

        if (maxi==INT_MIN) {
            return "";
        }
        else 

        {s.push_back(maxi+'0');
        s.push_back(maxi+'0');
        s.push_back(maxi+'0');}

        return s;
        
    }
};