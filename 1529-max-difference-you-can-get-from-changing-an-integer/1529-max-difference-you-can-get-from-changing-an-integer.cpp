class Solution {
public:
    int maxDiff(int num) {
        string number = to_string(num);
        int n = number.length();
        string temp = number;
        char s; char e;

        for (int i=0; i<n; i++) {
            if (temp[i]!='9'){
                s = temp[i];
                break;
            }
        }
        char t = number[0];
        for (int i=0; i<n; i++) {
            if (i>0 && t == '1' && number[i]!='0' &&number[i]!='1') {
                e = temp[i];
                break;
            }
            else if (number[i]!='1' && number[i]!='0') {
                e=temp[i];
                break;
            }
        }

        for (int i=0; i<n; i++) {
            if (temp[i]==s) {
                temp[i] = '9';
            }
        }
        
        for (int i=0; i<n; i++) {
            if (t == e && number[i]==e) {
                number[i] = '1';
            }
            else if(number[i]==e) {
                number[i] = '0';
            }
        }
        int big = stoi(temp);
        int small = stoi(number);
        return big-small;

    }
};