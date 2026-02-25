class Solution {
    int reverse(int num) {
        int temp = 0;
        while (num && num%10 == 0) {
            num/=10;
        }
        while (num) {
            temp = temp*10 + num%10;
            num/=10;
        }

        return temp;
    }
public:
    bool isSameAfterReversals(int num) {
        int rev = reverse(num);
        int drev = reverse(rev);

        return num == drev;
    }   
};