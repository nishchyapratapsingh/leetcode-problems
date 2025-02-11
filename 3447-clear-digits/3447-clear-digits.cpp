class Solution {
public:
    string clearDigits(string s) {
        string result;
        stack<int> intstack;

        for (int i=0; i<s.length(); i++) {

            intstack.push(s[i]);

            if (!empty(intstack) && intstack.top() >= '0' && intstack.top() <= '9') {
                
                intstack.pop();
                if (!empty(intstack)) intstack.pop();
            }

        }

        while (!empty(intstack)) {
            result.push_back(intstack.top());
            intstack.pop();
        }

        reverse(result.begin(), result.end());

        return result;

    }

};