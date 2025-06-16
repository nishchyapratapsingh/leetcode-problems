class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l=0;
        int currWinP = 0;
        int totalScore = 0;
        int minScore = INT_MAX;

        for (int r=0; r<n; r++) 
        {
            currWinP += cardPoints[r];
            if(r-l+1 ==n- k) minScore = min(minScore, currWinP); //first window score
            if (r-l+1 > n-k) {
                currWinP-=cardPoints[l];
                minScore = min(minScore, currWinP); //next window scores
                l++;
            }
            
            
            
        }

        for (int i=0; i<n; i++) {
            totalScore += cardPoints[i];
        }

        return totalScore - minScore;
    }
};