class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int> help=nums;
        int n=nums.size();
        int i=0; int j=n-1;
        for (int num: nums) {
            num = (num%2==0?0:1);
            if (i<=j) {
                if(num==0){
                    help[i]=0;
                    i++;
                }
                else {
                    help[j]=1;
                    j--;
                }
            }
        }
        return help;

    }
};