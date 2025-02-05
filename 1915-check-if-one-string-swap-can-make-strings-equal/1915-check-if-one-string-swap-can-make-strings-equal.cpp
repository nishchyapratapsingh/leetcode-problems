class Solution {

private:
    bool isEqual(const string &s1, const string &s2) {
        return s1==s2;
    }
    
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.length() != s2.length()) return false;

        if (isEqual(s1, s2)) return true;
       

        int n = s1.length();
        int arr[3];
        int j=0;

        for (int i=0; i<n; i++) {

            if (s1[i] != s2[i]) {
                arr[j] = i;
                j++;
            }

            if (j > 2) return false;
        }

        swap (s1[arr[0]], s1[arr[1]]);
        
        if (isEqual(s1, s2)) return true;

        return false;
    }
};