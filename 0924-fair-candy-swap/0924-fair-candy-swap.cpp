class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int m=aliceSizes.size();
        int n=bobSizes.size();
        sort(aliceSizes.begin(), aliceSizes.end());
        sort(bobSizes.begin(), bobSizes.end());
        int totalAlice=0, totalBob=0;
        for (int num: aliceSizes) {
            totalAlice+=num;
        }
        for (int num: bobSizes) {
            totalBob+=num;
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (totalBob+aliceSizes[i]-bobSizes[j]==totalAlice+bobSizes[j]-aliceSizes[i]) {
                    return {aliceSizes[i], bobSizes[j]};
                }
            }
        }
        return {0,0};

    }
};