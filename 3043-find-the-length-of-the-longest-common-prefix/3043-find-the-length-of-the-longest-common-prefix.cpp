class Solution {
private:
    void f(int num, unordered_map<int, int> &mp) {
        string str = to_string(num);

        string cur;
        int size = 0;
        for (char c: str) {
            cur.push_back(c);
            size++;
            mp[stoi(cur)] = size;
        }
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size();
        int n = arr2.size();
        int ans = 0;
        unordered_map<int, int> mp;

        for (int num: arr1) {
            f(num, mp);
        }

        for (int num: arr2) {
            string str = to_string(num);
            string cur;

            for (char c: str) {
                cur.push_back(c);
                int t = stoi(cur);
                if (mp.count(t)) {
                    ans = max(ans, mp[t]);
                }
            }
        }

        return ans;
    }
};