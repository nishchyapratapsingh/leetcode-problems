class Solution {
private:
    bool checkequal (int a[], int b[]) {
        int n = 26;
        for (int i=0; i<n; i++) {
            if (a[i] != b[i]) return 0;
        }

        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length()) return false;

        int count1[26] = {0};

        for (int i=0; i<s1.size(); i++) {
            count1[s1[i] - 'a']++;
        }

        int windowsize = s1.length();
        int count2[26] = {0};

        int i = 0;
        while (i<windowsize) {
            count2[s2[i] - 'a']++;
            i++;
        }

        if (checkequal (count1, count2)) return true;

        while (i < s2.length()) {
            char newchar = s2[i];
            char oldchar = s2[i - windowsize];

            count2[newchar - 'a']++;
            count2[oldchar - 'a']--;

            if (checkequal (count1, count2)) return true;

            i++;
        }

    return false;
    }
};