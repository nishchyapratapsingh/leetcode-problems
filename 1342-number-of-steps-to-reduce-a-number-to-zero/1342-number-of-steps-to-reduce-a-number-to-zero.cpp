class Solution {
    int cnt=0;
public:
    int numberOfSteps(int num) {
        if (num==0) return cnt;

        if (num%2==0) num/=2;
        else num-=1;

        cnt++;

        numberOfSteps(num);
        return cnt;
    }
};