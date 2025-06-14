class Solution {
public:
    int minMaxDifference(int num) {
        string number = to_string(num);
        int n=number.length();
        int s;
        int e;
        string temp = number;
        for (int i=0; i<n; i++) {
            if(number[i]=='9'){
                continue;
            }
            s=number[i];
            break;
        }

        for (int i=0; i<n; i++) {
            if(number[i]=='0'){
                continue;
            }
            e=number[i];
            break;
        }

        for (int i=0; i<n; i++) {
            if (number[i]==s){
                temp[i]='9';
            }
        }

        int big = stoi(temp);

        for (int i=0; i<n; i++) {
            if (number[i]==e) {
                number[i]='0';
            }
        }

        int small = stoi(number);

        return big-small;

    }
};