class Solution {
public:
    string interpret(string command) {
        int i=0; 
        int n = command.length();
        string res;
        while (i<n) {
            if (command[i] == 'G') {
                res.push_back('G');
                i++;
            }
            else if (command[i] == '(') {
                if (command[i+1] == ')') {
                    res.push_back('o');
                    i+=2;
                }
                else {
                    res += "al";
                    i+=4;
                }
            }
        }
        return res;
    }
};