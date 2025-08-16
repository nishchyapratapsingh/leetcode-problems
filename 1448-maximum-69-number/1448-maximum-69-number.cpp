class Solution {
public:
    int maximum69Number (int num) {
        vector<int> arr;
        while (num) {
            arr.push_back(num%10);
            num/=10;
        }
        reverse(arr.begin(), arr.end());
        for (int i=0; i<arr.size(); i++) {
            if (arr[i]==6) {
                arr[i] = 9;
                break;
            }
        }
        int res=0;
        for (int digit: arr) {
            res = res*10+digit;
        }
        return res;
    }
};