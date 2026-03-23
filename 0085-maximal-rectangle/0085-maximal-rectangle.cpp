class Solution {
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n = heights.size();
        vector<int> nse(n);
        vector<int> pse(n);
        
        for (int i = n-1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                pse[s.top()] = i;
                s.pop();
            }
            if (!s.empty()) {
                nse[i] = s.top();
            }
            else {
                nse[i] = n;
            }

            s.push(i);
        }

        while (!s.empty()) {
            pse[s.top()] = -1;
            s.pop();
        }
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, (nse[i] - pse[i] - 1) * heights[i]);
        }

        return mx;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int mx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                heights[j] = matrix[i][j] == '0' ? 0 : heights[j]+1;
            }
            mx = max(mx, largestRectangleArea(heights));
        }

        return mx;
    }
};