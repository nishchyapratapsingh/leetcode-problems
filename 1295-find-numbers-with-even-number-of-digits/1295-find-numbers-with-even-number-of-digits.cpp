class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;

        for (int num : nums) {
            if (num > 0) {
                if (num > 9) {
                    if (num > 99) {
                        if (num > 999) {
                            if (num > 9999) {
                                if (num > 99999) {
                                    cnt++;
                                    continue;
                                }
                                continue;
                            }
                            cnt++;
                            continue;
                        }
                        continue;
                    }
                    cnt++;
                    continue;
                }
                continue;
            }
        }

        return cnt;
    }
};