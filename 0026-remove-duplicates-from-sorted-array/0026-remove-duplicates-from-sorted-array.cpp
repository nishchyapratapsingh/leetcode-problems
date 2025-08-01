 class Solution {
public:
    int removeDuplicates(vector<int>& arr) {

        int i=0;
        int j=1; int n=arr.size();
        if (n==0) return 0;
        while (i<n && j<n) {
            if(arr[j]!=arr[i]) {
                arr[++i] = arr[j];
            }
            j++;
        }

        return i+1;
    }
};