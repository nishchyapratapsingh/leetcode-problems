class Solution {
    bool selfDiv(int num) {
        int temp = num;

        while (temp) {
            if (temp % 10 == 0 || num % (temp%10) != 0) return false;
            temp/=10;
        }

        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int num = left; num <= right; num++) {
            if(selfDiv(num)) ans.push_back(num);
        }

        return ans;
    }
};