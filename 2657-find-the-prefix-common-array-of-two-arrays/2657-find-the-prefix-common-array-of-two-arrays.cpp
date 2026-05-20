class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        int n = A.size();
        int cnt = 0;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            mp1[A[i]]++;
            mp2[B[i]]++;

            if (mp2.count(A[i]) && mp1[A[i]] == mp2[A[i]]) {
                cnt++;
            }
            if (A[i] != B[i] && mp1.count(B[i]) && mp1[B[i]] == mp2[B[i]]) {
                cnt++;
            }

            ans[i] = cnt;
        }

        return ans;
    }
};