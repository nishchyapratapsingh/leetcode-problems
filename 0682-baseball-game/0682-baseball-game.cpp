class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        int prev;
        for (string op : operations) {
              if (op == "+") {
                int t = s.top();
                s.push(t+prev);
                prev = t;
              }
              else if (op == "D") {
                int t = s.top();
                s.push(2*t);
                prev = t;
              }
              else if (op == "C") {
                int k = 2;
                s.pop();
                
                if (!s.empty()) {
                    int t = s.top();
                    s.pop();
                    if (!s.empty()) prev = s.top();
                    s.push(t);
                }
              }
              else {
                if (!s.empty()) prev = s.top();
                s.push(stoi(op));
              }
        }

        int ans = 0;
        while (!s.empty()) {
            ans+=s.top();
            s.pop();
        }

        return ans;
    }
};