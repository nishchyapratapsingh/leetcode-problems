class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int maxA = INT_MIN;
        while (i<j) {
            int currArea = min(height[i], height[j])*(j-i);
            maxA = max(currArea, maxA);
            if (height[i]<height[j]) i++;
            else if (height[i]>height[j]) j--;
            else {
                i++; 
                j--;
            }
        }
        return maxA;
    }
};