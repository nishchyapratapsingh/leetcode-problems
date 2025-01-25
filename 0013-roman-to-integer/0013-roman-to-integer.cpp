class Solution {
public:
    int value(char c) {
        switch(c) {
            case 'M':
                return 1000;
            case 'D':
                return 500;
            case 'C':
                return 100;
            case 'L':
                return 50;
            case 'X':
                return 10;
            case 'V':
                return 5;
            case 'I':
                return 1;

        }

        return 0;
    }

    int romanToInt(string s) {
        int result=0;

        for (int i=0; i<s.length(); i++) {
            if ( (i+1)<s.length() && value(s[i]) < value(s[i+1]) ) {
                result -= value(s[i]);
               
            }
         else
            result += value(s[i]);
        }

        return result;
    }
};