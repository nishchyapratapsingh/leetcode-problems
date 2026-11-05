class Solution {
    int findNearest(int n, vector<int> &arr2) {
        int s = 0;
        int e = arr2.size() - 1;
        int m = s + (e - s) / 2;

        while (s < e) {
            if (arr2[m] == n) {
                return n;
            }

            else if (arr2[m] < n) {
                s = m + 1;
            }

            else {
                e = m;
            }

            m = s + (e - s) / 2;
        }

        if (s > 0 && abs(arr2[s-1] - n) < abs(arr2[s] - n)) {
            return arr2[s-1];
        }

        return arr2[s];
    }
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = 0;

        for (int e : arr1) {
            int t = findNearest(e, arr2);
            if (abs(t - e) > d) {
                ans++;
            }
        }

        return ans;
    }
};