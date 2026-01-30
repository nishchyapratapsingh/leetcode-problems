class Solution {
    int solve(int num) {
        int len = 0;
        int temp = num;

        while (temp) {
            len++;
            temp/=10;
        }

        if (len % 2 != 0) return 0;
        int t1 = 0, t2 = 0;
        temp = len/2;
        while (temp--){
            t1 += num%10;
            num/=10;
        }
        temp = len/2;
        while (temp--){
            t2 += num%10;
            num/=10;
        }
        return t1 == t2 ? 1 : 0;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        // int l1 = 0, l2 = 0;
        // int temp = low;

        // while (temp) {
        //     l1++;
        //     temp/=10;
        // }
        // temp = high;
        // while (temp) {
        //     l2++;
        //     temp/=10;
        // }

        // if (l1%2 != 0) {
        //     if (low*10 <= high) {
        //         low = low*10;
        //     }
        //     else return 0;
        // }

        int cnt = 0;
        for (int i = low; i <= high; i++) {
            cnt += solve(i);
        }

        return cnt;
    }
};